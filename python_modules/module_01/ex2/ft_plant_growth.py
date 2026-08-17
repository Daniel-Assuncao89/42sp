# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_growth.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/04 16:14:10 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 15:11:21 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:

    def __init__(
            self, name: str, height: float, days: int,
            growth: float = 0.8) -> None:
        self.name = name
        self.height = round(height, 1)
        self.days = days
        self.week_growth = 0.0
        self.growth = growth

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def grow(self) -> None:
        self.height = round(self.height + self.growth, 1)
        self.week_growth += round(self.growth, 1)

    def age(self) -> None:
        self.days += 1

    def total_growth(self) -> None:
        for day in range(1, 8):
            self.grow()
            self.age()
            print(f"=== Day {day} ===")
            self.show()
        print(f"Growth this week: {self.week_growth}cm")


def main() -> None:
    print("=== Garden Plant Growth ===")
    rose = Plant("Rose", 25.0, 30)
    rose.show()
    rose.total_growth()


if __name__ == "__main__":
    main()
