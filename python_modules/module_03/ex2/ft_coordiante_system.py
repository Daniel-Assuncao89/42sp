# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_coordiante_system.py                           :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/20 13:37:30 by dassunca        #+#    #+#               #
#  Updated: 2026/08/20 16:23:27 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import math


def get_player_pos() -> None:

    fisrt_tuple: tuple = tuple()
    second_tuple: tuple = tuple()
    print("=== Game Coordinate System ===\n")
    print("Get a fisrt set of coordinates")
    while not fisrt_tuple:
        print("Enter new coordinates as floats in format: 'x,y,z':", end="")
        user_coordinates1 = input()
        fisrt_tuple = tuple(Handler_exception(user_coordinates1))
    print(f"Got a first tuple: {fisrt_tuple}")
    pythagorean_calc(fisrt_tuple)

    print("Get a second set of coordinates")
    while not second_tuple:
        print("Enter new coordinates as floats in format: 'x,y,z':", end="")
        user_coordinates2 = input()
        second_tuple = tuple(Handler_exception(user_coordinates2))
    pythagorean_calc(fisrt_tuple, second_tuple, set_coord=2)


def Handler_exception(user_coordinates: str) -> list:

    coordinates_list: list = []
    if ',' not in user_coordinates:
        print("Invalid syntax")
        return []
    try:
        for coord in user_coordinates.split(','):
            coordinates_list.append(float(coord))
    except ValueError as e:
        print(f"Error on parameter '{coord}': {e}")
        return []
    return coordinates_list


def pythagorean_calc(
        coord1: tuple,
        coord2: tuple = (0, 0, 0),
        set_coord: int = 1
        ) -> None:

    x1, y1, z1 = (coord1)
    if set_coord == 1:
        print(f"It includes: X={x1}, Y={y1}, Z={z1}")
    x2, y2, z2 = (coord2)
    pythagorean_result = math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)
    print(f"Distance to center: {pythagorean_result:.4f}\n")


if __name__ == "__main__":
    get_player_pos()
