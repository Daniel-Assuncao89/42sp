# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_data_alchemist.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/28 20:09:19 by dassunca        #+#    #+#               #
#  Updated: 2026/09/03 18:23:22 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import random


def data_alchemist() -> None:
    print("=== Game Data Alchemist ===\n")
    list_of_player: list = ["Alice", "bob", "Charlie", "dylan", "Emma",
                            "Gregory", "john", "kevin", "Liam"]
    list_cap: list = [player.capitalize() for player in list_of_player]
    only_cap: list = [player
                      for player in list_of_player
                      if player[0].isupper()]

    print("Initial list of player", list_of_player)
    print("New list with all names capitalized: ", list_cap)
    print("New list of capitalized names only: ", only_cap)
    dict_player = {
        player: random.choice(range(1, 700))
        for player in list_of_player
    }
    avg_score = sum(dict_player.values()) / len(list_of_player)

    print(f"Score dict: {dict_player}")
    print(f"Score avarage is {avg_score:.2f}")
    high_score = {
        key: value
        for key, value in dict_player.items()
        if value > avg_score
    }
    print(f"High scores: {high_score}")


if __name__ == "__main__":
    data_alchemist()
