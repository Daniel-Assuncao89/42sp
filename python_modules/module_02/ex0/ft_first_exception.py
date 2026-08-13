# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_first_exception.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/13 15:17:50 by dassunca        #+#    #+#               #
#  Updated: 2026/08/13 16:02:37 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def input_temperature(temp_str: str) -> int:
    return int(temp_str)

def test_temperature() -> None:
    try:
        user_input = input()
        print(f"Input data is now '{user_input}'")
        temp = input_temperature(user_input)
        print(f"Temperature is {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print("All tests completes - program  did't crash!")

if __name__ == "__main__":
    test_temperature()