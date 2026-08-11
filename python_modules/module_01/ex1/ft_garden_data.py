# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_data.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/04 16:13:53 by dassunca        #+#    #+#               #
#  Updated: 2026/08/11 13:45:19 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


def ft_garden_data():
    print("=== Garden Plant Registry ===")
    flower = Plant("Rose", 25, 23)
    flower.show()
    sunflower = Plant("Sunflower", 80, 45)
    sunflower.show()
    cactus = Plant("Cactus", 15, 120)
    cactus.show()


if __name__ == "__main__":
    ft_garden_data()
