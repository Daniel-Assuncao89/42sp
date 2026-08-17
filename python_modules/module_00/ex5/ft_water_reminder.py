# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_water_reminder.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/17 13:39:06 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 13:39:07 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_water_reminder():
    print("Days since last watering:", end="")
    days = int(input())
    if (days > 2):
        print("Water the plants!")
    else:
        print("Plants are fine")
