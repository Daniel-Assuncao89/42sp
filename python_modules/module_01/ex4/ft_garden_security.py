# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_security.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/04 19:57:23 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 15:04:03 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    def __init__(self, name: str, height: float, days: int,) -> None:
        self._name = name.capitalize()
        self._height = 10.0
        self._days = 5
        if self.validations(height=height, days=days):
            self._height = round(height, 1)
            self._days = days
            print(f"Plant created: {self._name}: {self._height}cm, \
{self._days} days old\n")
        else:
            print("Invalid values provided. Plant created with default values")

    def current_state(self) -> None:
        print(
            f"Current state: {self._name}: \
            {self._height}cm, {self._days} days old")

    def get_height(self) -> float:
        return (self._height)

    def get_age(self) -> int:
        return (self._days)

    def set_height(self, height: float) -> None:
        if self.validations(height=height):
            self._height = round(height, 1)
            print(f"Height updated: {self._height}")
        else:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")

    def set_age(self, days: int) -> None:
        if self.validations(days=days):
            self._days = days
            print(f"Age updated: {self._days} days\n")
        else:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected\n")

    def validations(self, height: float = None, days: int = None) -> bool:
        if (self._height < 0 or self._days < 0):
            return False
        if (
            (height is not None and height < 0) or
            (days is not None and days < 0)
        ):
            return False
        return True


def main() -> None:
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15.0, 10)
    rose.set_height(25.0)
    rose.set_age(30)
    rose.set_height(-25.0)
    rose.set_age(-30)
    rose.current_state()


if __name__ == "__main__":
    main()
