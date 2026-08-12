# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_types.py                                 :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/11 13:37:20 by dassunca        #+#    #+#               #
#  Updated: 2026/08/12 16:45:23 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #
class Plant:
    def __init__(self, name: str, height: float, age: int,) -> None:
        self._name = name.capitalize()
        self._height = 10.0
        self._age = 5
        if self.validations(height=height, age=age):
            self._height = round(height, 1)
            self._age = age
    
    def show(self) -> None:
        print(f"{self._name}: {self._height}cm, {self._age} days old")

    def get_height(self) -> float:
        return (self._height)

    def get_age(self) -> int:
        return (self._age)

    def set_height(self, height: float) -> None:
        if self.validations(height=height):
            self._height = round(height, 1)

    def set_age(self, age: int) -> None:
        if self.validations(age=age):
            self._age = age

    def validations(self, height: float = None, age: int = None) -> bool:
        if (self._height < 0 or self._age < 0):
            return False
        if ((height is not None and height < 0) or 
            (age is not None and age < 0)):
            return False
        return True


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._blooming = False
        print(f"=== Flower")

    def show(self) -> None:
        super().show()
        print(f"Color: {self._color}")
        if self._blooming:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")
    
    def bloom(self) -> None:
        print(f"[asking the {self._name} to bloom]")
        self._blooming = True


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter
        print(f"=== Tree")

    def show(self) -> None:
        super().show()
        print(f"Trunk Diameter: {self._trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(f"[asking the {self._name} to produce shade]")
        print(f"Tree {self._name} now produces a shade of {self._height}cm long and {self._trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int, harvest_season: str, nutritional_value: int = 0) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value
        print(f"=== Vegetable")

    def show(self) -> None:
        super().show()
        print(f"Harvest Season: {self._harvest_season.capitalize()}")
        print(f"Nutritional Value: {self._nutritional_value}")
    
    def grow(self):
        self.set_height(self._height + 2.1)

    def age(self, days: int = 1):
        print(f"[make {self._name} grow and age for {days} days]")
        for day in range(days):
            self.set_age(self._age + 1)
            self.grow()
            self._nutritional_value += 1

def main() -> None:
    print("=== Garden Security System ===")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    rose.bloom()
    rose.show()
    print("")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    oak.produce_shade()
    print("")
    tomato = Vegetable("tomato", 5.0, 10, "april")
    tomato.show()
    tomato.age(20)
    tomato.show()

if __name__ == "__main__":
    main()
