# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_seed_inventory.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/17 13:38:58 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 13:38:59 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_seed_inventory(seed_type: str, quantity: int,  unit: str) -> None:
    if unit == "packets":
        print(f"{seed_type.capitalize()} seeds: {quantity} packets available")
    elif unit == "grams":
        print(f"{seed_type.capitalize()} seeds: {quantity} grams total")
    elif unit == "area":
        print(
            f"{seed_type.capitalize()} seeds: covers {quantity} square meters")
    else:
        print(
            f"Unknown unit: {unit}. Please use 'packets', 'grams', or 'area'.")
