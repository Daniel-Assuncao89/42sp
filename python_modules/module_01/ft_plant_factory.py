# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_factory.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/04 16:59:47 by dassunca        #+#    #+#               #
#  Updated: 2026/08/04 19:55:51 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:

    def __init__(
            self, name: str, height: float, days: int,
            growth: float = 0.5785) -> None:
        self.name = name
        self.height = round(height, 1)
        self.days = days
        self.week_growth = 0
        self.growth = growth

    def show(self) -> None:
        print(f"Created: {self.name}: {self.height}cm, {self.days} days old")

    def grow(self) -> None:
        self.height = round(self.height + self.growth, 1)
        self.week_growth += round(self.growth, 1)

    def age(self) -> None:
        self.days += 1


def main() -> None:
    print("=== Plant Factory Output ===")
    sunflower = Plant("Sunflower", 80.0, 45)
    rose = Plant("Rose", 25.0, 30)
    oak = Plant("Oak", 200.0, 365)
    cactus = Plant("Cactus", 5.0, 90)
    fern = Plant("Fern", 15.0, 120)
    rose.show()
    oak.show()
    cactus.show()
    sunflower.show()
    fern.show()


if __name__ == "__main__":
    main()
