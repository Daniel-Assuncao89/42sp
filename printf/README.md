*This project has been created as part of the 42 curriculum by dassunca.*

---

## 📄 Description

### Overview

**ft_printf** is a custom implementation of the standard C library function `printf`. The project is a fundamental milestone in the 42 curriculum, designed to deconstruct and rebuild one of the most versatile and widely used functions in C. Rather than relying on high-level abstractions, this implementation handles low-level memory formatting, data type translation, and system-level output buffering from scratch.

At its core, the project processes a formatted string, intercepts specific format specifiers (flags prefixed by `%`), fetches arguments from a variable-length list utilizing the `<stdarg.h>` library, and outputs the exact number of bytes written to the standard output.

### Goal

The primary objective of `ft_printf` is to create a highly optimized, memory-safe, and fully compliant replica of the original `printf` function that adheres strictly to the **ISO C standard**, handling a specific subset of format specifiers.

Beyond its immediate functionality, the project serves to deepen the developer's mastery over:

* **Variadic Functions:** Managing an arbitrary number of function arguments dynamically using macro manipulations (`va_start`, `va_arg`, `va_end`).
* **Type Promotion & Hardware Architecture:** Understanding how types like `char` are promoted to `int` in variadic contexts, and how pointer sizes scale between 32-bit and 64-bit architectures.
* **Low-Level Data Conversion:** Transforming raw binary representations of integers, unsigned values, pointers, and hexadecimals into human-readable ASCII character streams without utilizing forbidden standard library converters.

---

## 🛠️ Technical Choices: Algorithms and Data Structures

### 1. Algorithm: Successive Divisions via Recursion

For all numerical conversion specifiers (`%d`, `%i`, `%u`, `%x`, `%X`, and `%p`), the chosen core algorithm is **Successive Division**.

* **Justification for Recursion over Loops:** When dividing a number mathematically (by base 10 or base 16), the digits are extracted from **right to left** (least significant to most significant). However, `write` must display them from **left to right**.
* **Memory Optimization:** Instead of allocating a heap-based dynamic string buffer (`malloc`) to store and reverse the characters, this approach utilizes the system's **Call Stack (LIFO - Last In, First Out Philosophy)**. The function drills down to the first digit before executing the `write` calls on the way back up. This guarantees **zero risk of memory leaks** and strictly complies with the 42 line-limit constraint per function.
* **Accurate Output Counting:** The recursive unwind pattern (`count += ft_function()`) elegantly tracks and aggregates the exact number of bytes written across nested calls without needing complex global state trackers or extra pointer arguments.

### 2. Data Structures and Type Configurations

* **Static Translation Tables (Lookup Arrays):** For hexadecimal conversions (`%x`, `%X`, and `%p`), the algorithm utilizes string literals as static mapping dictionaries (e.g., `"0123456789abcdef"`). The remainder of the division (`nbr % 16`) acts as an immediate index array shift. This guarantees **$O(1)$ constant time complexity** for character selection, removing complex conditional branches.
* **`unsigned long long` / `uintptr_t` for `%p`:** Pointer sizes vary across architectures (4 bytes on 32-bit vs. 8 bytes on 64-bit). To process memory addresses, the absolute memory address value is recast into an `unsigned long long`. This wide integer type ensures that memory representations never suffer from **truncation** or **overflow**.
* **`long` Type Promotion for Signed Integers (`%d` / `%i`):** The edge case of the absolute minimum integer (`-2147483648`) cannot be safely multiplied by `-1` within a standard `int` due to structural asymmetry (overflowing past `2147483647`). Upcasting the variable into a `long` structure temporarily bypasses this barrier, guaranteeing arithmetic safety.

---

## 💻 Instructions

### Compilation and Installation

The project is packaged with a strict `Makefile` that compiles the source files into a static library archive named `libftprintf.a`.

1. **Clone the repository and enter the directory:**

2. **Compile the library using make:**

*This will compile all `.c` files using `cc` with the flags `-Wall -Wextra -Werror` and generate `libftprintf.a`.*
3. **Cleaning management rules:**
* Remove object files: `make clean`
* Remove object files and the library binary: `make fclean`
* Force full recompilation: `make re`



### Execution and Integration

To test or implement `ft_printf` in an external application, include your header file and link the compiled library signature during compilation.

**Example usage (`main.c`):**

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! The answer is %d.\n", "World", 42);
    ft_printf("Bytes printed: %d\n", count);
    return (0);
}

```

**Linking via Terminal:**

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program_test
./program_test

```

---

## 📚 Resources & AI Statement

### References and Documentation

* **C Library Manuals:** [GNU C Library (glibc) Documentation](https://www.gnu.org/software/libc/documentation.html) — reference guide on standard stream behaviors and formatting rules.
* **Variadic Variable Handling:** [ISO C Standard - `<stdarg.h>](https://www.google.com/search?q=%5Bhttps://en.cppreference.com/w/c/variadic%5D(https://en.cppreference.com/w/c/variadic))` — deep dive on variable length argument macros.

### AI Utilization Statement

Artificial Intelligence (Large Language Model) was integrated as a collaborative engineering partner throughout this project's development lifecycles:

* **Debugging & Diagnostics:** Applied AI to decrypt compiler linker logs (`/usr/bin/ld: undefined reference`), leading to structural evaluations of missing object pointers inside the Makefile automation.
* **Edge-Case Validation:** Leveraged AI code-reviews to safely handle architectural boundary conditions, specifically addressing integer inversion boundaries (`-2147483648`) and type promotions within variadic arguments.
* **Documentation Pipeline:** Utilized AI to refine and organize technical descriptions, formatting code layouts, and structuring this document to match professional standard criteria.
