# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_security.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/04 19:57:23 by dassunca        #+#    #+#               #
#  Updated: 2026/08/05 18:40:00 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    def __init__(self, name: str, height: float, days: int,) -> None:
        if self.validations():
            self._name = name
            self._height = round(height, 1)
            self._days = days
            print(f"Plant created: \
                  {self._name.capitalize()}: {self._height}cm, \
                    {self._days} days old")

    def get_height(self) -> float:
        return (self._height)

    def validations(self) -> bool:
        if (self._height < 0 or self.days < 0):
            return False
        return True


def main() -> None:
    print("=== Garden Plant Growth ===")
    rose = Plant("Rose", 25.0, 30)
    rose.show()
    rose.total_growth()


if __name__ == "__main__":
    main()
