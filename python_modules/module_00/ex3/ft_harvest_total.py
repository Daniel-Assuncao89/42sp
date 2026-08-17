# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_harvest_total.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/17 13:38:09 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 13:38:10 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_harvest_total() -> None:
    print("Day 1 harvest: ", end="")
    day1 = int(input())
    print("Day 2 harvest: ", end="")
    day2 = int(input())
    print("Day 3 harvest: ", end="")
    day3 = int(input())
    total = day1 + day2 + day3
    print(f"Total harvest: {total}")
