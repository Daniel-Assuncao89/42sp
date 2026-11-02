*This project has been created as part of the 42 curriculum by dassunca.*

# Codexion

## Description

Codexion is a concurrency simulation written in C with POSIX threads. A number of
coders sit around a circular table. Between every pair of neighbours lies one USB
dongle (as many dongles as coders). To compile, a coder needs **both** adjacent
dongles at once; afterwards the coder debugs, then refactors, then tries to compile
again. If a coder does not **start** a compile within `time_to_burnout` ms of the
start of their previous compile (or of the simulation), they burn out and the
simulation stops. It also stops when every coder has compiled at least
`number_of_compiles_required` times.

The goal is to share the dongles fairly (FIFO or EDF arbitration), without
deadlocks, starvation, data races or log corruption, and to detect a burnout
within 10 ms.

## Instructions

```bash
make                # builds ./codexion (-Wall -Wextra -Werror -pthread)
make re             # full rebuild
make clean / fclean # remove objects / objects + binary

./codexion number_of_coders time_to_burnout time_to_compile time_to_debug \
           time_to_refactor number_of_compiles_required dongle_cooldown scheduler
```

All numbers are non-negative integers in milliseconds (`number_of_coders >= 1`);
`scheduler` is exactly `fifo` or `edf`. Invalid input prints a usage message on
stderr and exits with status 1.

Examples:

```bash
./codexion 5 800 200 200 200 7 0 fifo     # no burnout expected
./codexion 5 800 200 200 200 7 50 edf     # with 50 ms dongle cooldown
./codexion 1 800 200 200 200 3 0 fifo     # one dongle: burns out at 800 ms
```

Log format: `timestamp_in_ms X has taken a dongle | is compiling | is debugging |
is refactoring | burned out`.

## Blocking cases handled

* **Deadlock prevention (Coffman's conditions).** A coder never holds one dongle
  while waiting for the other: it enqueues in the queues of **both** of its dongles
  with the same arrival ticket and takes them **atomically** (all-or-nothing, locking
  the two dongle mutexes in ascending index order). This breaks *hold and wait*; the
  ascending lock order additionally rules out circular waits on the mutexes. Because
  all requests are totally ordered (priority key + unique ticket), the globally best
  request is always at the top of both of its queues, so someone can always progress.
  With one coder (a single dongle) the coder simply waits for burnout.
* **Start-up symmetry breaking.** If all coders asked in ring order (1, 2, 3...), each
  would queue behind its neighbour and compiles would run one at a time. Even-numbered
  coders therefore wait 1 ms before their first request, so odd coders (non-adjacent)
  compile in parallel first.
* **Starvation prevention.** Dongles grant access through a min-heap priority
  queue. FIFO: key = arrival ticket. EDF: key = `last_compile_start +
  time_to_burnout`; ties are broken by the unique arrival ticket, so the policy is
  fully deterministic. A request that waits long keeps its place (FIFO) or gets an
  ever earlier deadline relative to others (EDF).
* **Dongle cooldown.** Each dongle stores `available_at = release_time +
  dongle_cooldown`. A coder that is first in line but facing a cooldown sleeps with
  `pthread_cond_timedwait` until the cooldown expires instead of busy-waiting.
* **Precise burnout detection.** A dedicated monitor thread checks every coder
  roughly every 0.5 ms (reading `last_compile_start` under the coder's mutex), so
  the `burned out` line appears within ~1-2 ms of the real deadline (limit: 10 ms).
  Sleeps are sliced (`usleep(500)`) and re-check the stop flag, so threads react
  quickly to the end of the simulation.
* **Log serialization.** One `log_mutex` protects both the output and the `stop`
  flag. A message is printed only if the simulation has not stopped, and the
  `burned out` message sets the flag in the same critical section, so no line is
  printed after the burnout and lines never interleave. The two `has taken a dongle`
  lines and `is compiling` are printed in one critical section, so they are always
  consecutive in the log.
* **Single coder.** With one coder there is one dongle; the coder takes it, can never
  compile, and burns out after `time_to_burnout` ms.

## Thread synchronization mechanisms

| Primitive | Protects / does |
|---|---|
| `pthread_t` per coder + 1 monitor | coders run the cycle; the monitor detects burnout / completion |
| `pthread_mutex_t` per dongle | state of the dongle: `in_use`, `available_at`, priority queue |
| `pthread_cond_t` per dongle | waiting room of coders; `timedwait` for cooldowns |
| `pthread_mutex_t` per coder | `last_compile_start` and `compiles` (shared with the monitor) |
| `pthread_mutex_t log_mutex` | output **and** the `stop` flag |
| `pthread_mutex_t ticket_mutex` | global arrival counter used as unique tie-breaker |

**Lock hierarchy** (never inverted): at most two dongle mutexes are held at once,
always in ascending index order (the waited dongle first, then its pair); `log_mutex`
(read of the stop flag) is a leaf taken inside them. Coder mutexes and `ticket_mutex`
are leaves and are never held together with another lock.

**Race conditions prevented — examples**

* Two coders cannot take the same dongle: `in_use` is tested and set while holding
  that dongle's mutex, and only the head of the heap may take it.
* No lost wake-up: a coder checks its condition and calls `pthread_cond_wait` while
  holding the mutex of the dongle it waits on. A releasing coder updates the dongle
  under its mutex and then broadcasts on that dongle **and on its two neighbours**
  (locking each mutex), so a waiter can never miss the event.
* Monitor vs. coder: `last_compile_start` is written by the coder and read by the
  monitor only under the coder's mutex.
* Stopping: whoever stops the simulation sets `stop` under `log_mutex` and then
  broadcasts on every dongle condition (taking each mutex), waking sleeping coders.
* No global variables: everything lives in a `t_sim` structure on `main`'s stack.

## Project structure

```
Makefile  README.md
includes/codexion.h
src/  main.c parse.c parse_utils.c init.c cleanup.c run.c
      time_utils.c log.c heap.c heap_utils.c
      dongle.c pair.c coder.c coder_actions.c monitor.c
```

## Resources

* `man 3 pthread_create`, `pthread_mutex_lock`, `pthread_cond_wait`,
  `pthread_cond_timedwait`, `clock_gettime`.
* *Operating Systems: Three Easy Pieces* — chapters on concurrency (locks, condition
  variables, deadlock).
* Coffman et al., *System Deadlocks* (1971) — the four necessary conditions.
* Liu & Layland (1973) — Earliest Deadline First scheduling.
* Cormen et al., *Introduction to Algorithms* — binary heaps / priority queues.

**Use of AI:** Discuss the design of the synchronization strategy, to review edge cases, and to generate test scripts.
All code was reviewed, tested and is fully understood by the author.>
