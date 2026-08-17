# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_count_harvest_recursive.py                     :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/17 13:37:54 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 13:37:55 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_count_harvest_recursive(days=None, index=None):
    if days is None:
        print("Days until harvest: ", end="")
        days = int(input())
        index = 1
    elif days > 0:
        print(f"Day {index}")
        ft_count_harvest_recursive(days - 1, index + 1)
    elif days == 0:
        print("Harvest time!")
