# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_data_alchemist.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/28 20:09:19 by dassunca        #+#    #+#               #
#  Updated: 2026/08/28 21:18:21 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import random


def data_alchemist() -> None:
    list_of_player: list = ["Alice", "bob", "Charlie", "dylan", "Emma",
                            "Gregory", "john", "kevin", "Liam"]
    list_cap: list = [player.capitalize() for player in list_of_player]
    only_cap: list = [player
                      for player in list_of_player
                      if player[0].isupper()]
    print("Initial list of player", list_of_player)
    print("New list with all names capitalized: ", list_cap)
    print("New list of capitalized names only: ", only_cap)
    print(random.sample(range(1, 600), k=7))


if __name__ == "__main__":
    data_alchemist()
