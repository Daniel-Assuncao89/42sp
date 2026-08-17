# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_different_errors.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/13 16:20:15 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 18:41:01 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def garden_operations(operation_number: int) -> None:
    if (operation_number == 0):
        int("abc")
    elif (operation_number == 1):
        1 / 0
    elif (operation_number == 2):
        open("non_existent_file.txt", "r")
    elif (operation_number == 3):
        text = "test"
        number = 938
        _ = text + number


def test_error_types():
    print("=== Garden Error Types Demo ===\n")
    test_values = [0, 1, 2, 3]
    for value in test_values:
        try:
            print(f"Testing operation {value}")
            garden_operations(value)

        except ValueError as e:
            print(f"Caught ValueError: {e}\n")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}\n")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}\n")
        except TypeError as e:
            print(f"Caught TypeError: {e}\n")
    print("Operation completed successfully")
    print("\nAll error types tested sucessfully!")


if __name__ == "__main__":
    test_error_types()
