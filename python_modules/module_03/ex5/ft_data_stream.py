# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_data_stream.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/26 15:10:44 by dassunca        #+#    #+#               #
#  Updated: 2026/09/03 18:22:15 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

from typing import Generator
import random


def gen_event() -> Generator[tuple, None, None]:
    players: list[str] = ["Alice", "bob", "Charlie", "dylan"]
    actions: list[str] = ["run", "eat", "sleep", "grab", "move",
                          "climb", "swim", "release"]
    while True:
        player_event: tuple[str, str] = (
            random.choice(players), random.choice(actions)
            )
        yield player_event


def consume_event(events: list[tuple]) -> Generator[tuple, None, None]:
    while (events):
        picked = random.choice(events)
        events.remove(picked)
        yield picked


def ft_data_stream() -> None:
    event = gen_event()
    for i in range(1000):
        event_tuple = next(event)
        print(f"Event {i}: Player {event_tuple[0]} ", end="")
        print(f"did action {event_tuple[1]}")
    consume_events: list[tuple] = []
    for i in range(10):
        consume_events.append(next(event))
    print(f"Built list of 10 events: {consume_events}")
    for consume in consume_event(consume_events):
        print(f"Got event from list: {consume}")
        print(f"Remains on list: {consume_events}")


if __name__ == "__main__":
    ft_data_stream()
