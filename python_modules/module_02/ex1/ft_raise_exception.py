# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_raise_exception.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/13 15:43:12 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 15:08:37 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def input_temperature(temp_str: str) -> int:
    temp_str = int(temp_str)
    if (temp_str > 40):
        raise ValueError(f"{temp_str}°C is too hot for plants (max 40°C)")
    elif (temp_str < 0):
        raise ValueError(f"{temp_str}°C is too cold for plants (min 0°C)")
    return int(temp_str)


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===\n")
    test_values = ['25', 'abc', '100', '-50']
    for value in test_values:
        try:
            print(f"Input data is '{value}'")
            temp = input_temperature(value)
            print(f"Temperature is now {temp}°C\n")

        except ValueError as e:
            print(f"Caught input_temperature error: {e}\n")
    print("All tests completes - program  did't crash!")


if __name__ == "__main__":
    test_temperature()
