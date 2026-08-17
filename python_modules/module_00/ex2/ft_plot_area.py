# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plot_area.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/17 13:38:34 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 13:38:35 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_plot_area():
    print("Enter length:", end="")
    length = int(input())
    print("Enter width:", end="")
    width = int(input())
    area = length * width
    print(f"Plot area: {area}")
