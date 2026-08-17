# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_finally_block.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/13 17:54:12 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 15:09:29 by dassunca        ###   ########.fr        #
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


def water_plant(plant_name: str) -> None:

    if (plant_name.capitalize() in plant_name):
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system():
    print("Testing valid plants...")
    print("Opening watering system")

    try:
        for valid in ["Tomato", "Lettuce", "Carrots"]:
            water_plant(valid)
    finally:
        print("Closing watering system\n")

    print("Testing invalid plants...")
    print("Opening watering system")

    try:
        for invalid in ["Tomato", "lettuce", "Carrots"]:
            water_plant(invalid)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system\n")


if __name__ == "__main__":
    print("=== Garden Watering System ===\n")
    test_watering_system()
    print("Cleanup always happens, even with errors!")
