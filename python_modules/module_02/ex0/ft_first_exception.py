# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_first_exception.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/13 15:17:50 by dassunca        #+#    #+#               #
#  Updated: 2026/08/20 12:04:09 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    tests_input = ['25', 'abc']
    print("=== Garden Temperature ===\n")
    for test_input in tests_input:
        try:
            print(f"Input data is '{test_input}'")
            temp = input_temperature(test_input)
            print(f"Temperature is now {temp}°C\n")
        except ValueError as e:
            print(f"Caught input_temperature error: {e}\n")
    print("All tests completed - program  didn't crash!")


if __name__ == "__main__":
    test_temperature()
