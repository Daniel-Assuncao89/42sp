# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_count_harvest_iterative.py                     :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/17 13:36:52 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 13:36:53 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_count_harvest_iterative() -> None:
    print("Days until harvest: ", end="")
    days = int(input())
    for i in range(days):
        print(f"Day {i + 1}")
    print("Harvest time!")
