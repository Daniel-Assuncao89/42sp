# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_achievement_tracker.py                         :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/24 10:03:14 by dassunca        #+#    #+#               #
#  Updated: 2026/08/28 19:12:29 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import random


def find_common_achievments(
        achiev_set_1: set,
        achiev_set_2: set,
        achiev_set_3: set,
        achiev_set_4: set,
        ) -> None:
    common_achiev: set = achiev_set_1.intersection(
        achiev_set_2, achiev_set_3, achiev_set_4)
    print(f"\nCommon achievment: {common_achiev}\n")


def unique_achievments(
        unique_set: set,
        achiev_set_2: set,
        achiev_set_3: set,
        achiev_set_4: set,
        player: str
) -> None:
    unique_achiev: set = unique_set.difference(achiev_set_2, achiev_set_3,
                                               achiev_set_4)
    print(f"Only {player} has: {unique_achiev}")


def missing_achievments(
        compare_set: set,
        achiev_set: set,
        player: str,
) -> None:
    missing_achiev: set = compare_set.symmetric_difference(achiev_set)
    print(f"{player} is missing: {missing_achiev}")


def gen_player_achievements() -> None:

    achiev_list = ["Crafting Genius", "Strategist", "World Savior",
                   "Speed  Runner", "Survivor", "Master Explorer",
                   "Treasure Hunter", "Unstoppable", "First Steps",
                   "Collector Supreme", "Untouchable", "Sharp Mind",
                   "Boss Slayer"]

    achiev_set_player1: set = set(random.sample(achiev_list, k=6))
    achiev_set_player2: set = set(random.sample(achiev_list, k=7))
    achiev_set_player3: set = set(random.sample(achiev_list, k=10))
    achiev_set_player4: set = set(random.sample(achiev_list, k=5))

    print("=== Achievment Tracker System ===\n")
    print("Player Alice: ", achiev_set_player1)
    print("Player Bob: ", achiev_set_player2)
    print("Player Charlie: ", achiev_set_player3)
    print("Player Dylan: ", achiev_set_player3)
    print("\nAll distinct achievments: ",
          str(achiev_list).replace('[', '{').replace(']', '}'))
    find_common_achievments(achiev_set_player1, achiev_set_player2,
                            achiev_set_player3, achiev_set_player4)

    unique_achievments(
        unique_set=achiev_set_player1,
        achiev_set_2=achiev_set_player2,
        achiev_set_3=achiev_set_player3,
        achiev_set_4=achiev_set_player4,
        player="Alice",
    )

    unique_achievments(
        unique_set=achiev_set_player2,
        achiev_set_2=achiev_set_player1,
        achiev_set_3=achiev_set_player3,
        achiev_set_4=achiev_set_player4,
        player="Bob",
    )

    unique_achievments(
        unique_set=achiev_set_player3,
        achiev_set_2=achiev_set_player2,
        achiev_set_3=achiev_set_player1,
        achiev_set_4=achiev_set_player4,
        player="Charlie",
    )

    unique_achievments(
        unique_set=achiev_set_player4,
        achiev_set_2=achiev_set_player2,
        achiev_set_3=achiev_set_player3,
        achiev_set_4=achiev_set_player1,
        player="Dylan",
    )
    print("")
    missing_achievments(
        compare_set=achiev_set_player1,
        achiev_set=set(achiev_list),
        player="Alice"
    )

    missing_achievments(
        compare_set=achiev_set_player2,
        achiev_set=set(achiev_list),
        player="Bob"
    )

    missing_achievments(
        compare_set=achiev_set_player3,
        achiev_set=set(achiev_list),
        player="Charlie"
    )

    missing_achievments(
        compare_set=achiev_set_player4,
        achiev_set=set(achiev_list),
        player="Dylan"
    )


if __name__ == "__main__":
    gen_player_achievements()
