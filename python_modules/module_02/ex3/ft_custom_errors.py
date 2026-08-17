# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_custom_errors.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/13 16:42:07 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 15:08:50 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class GardenError(Exception):

    def __init__(self, message="Unknown garden error"):
        super().__init__(message)


class PlantError(GardenError):

    def __init__(self, message="Unknown plant error"):
        super().__init__(message)


class WaterError(GardenError):

    def __init__(self, message="Unknown water error"):
        super().__init__(message)


def main():
    print("=== Custom Garden Errors Demo ===\n")
    print("Testing PlantError...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except PlantError as e:
        print(f"Caught PlantError: {e}\n")

    print("Testing WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught WaterError: {e}\n")

    # Test catching all garden errors via parent class
    print("Testing catching all garden errors...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    try:
        raise WaterError("Not enough water in the tank!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    main()
