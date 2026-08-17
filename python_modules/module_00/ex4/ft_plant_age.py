# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_age.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/17 13:38:27 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 13:38:29 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_plant_age():
    print("Enter plant age in days:", end="")
    age = int(input())
    if (age > 60):
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
