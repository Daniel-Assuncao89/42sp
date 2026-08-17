# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_analytics.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/13 12:37:07 by dassunca        #+#    #+#               #
#  Updated: 2026/08/17 18:39:04 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    class PlantStats:
        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def increment_grow(self) -> None:
            self._grow_count += 1

        def increment_age(self) -> None:
            self._age_count += 1

        def increment_show(self) -> None:
            self._show_count += 1

        def display(self) -> None:
            print("Stats: ", end="")
            print(f"{self._grow_count} grow", end=", ")
            print(f"{self._age_count} age", end=", ")
            print(f"{self._show_count} show")

    def __init__(
        self,
        name: str,
        height: float,
        age: int
    ) -> None:
        self._name = name.capitalize()
        self._height = 10.0
        self._age = 5
        self._stats = Plant.PlantStats()

        if self.validations(height=height, age=age):
            self._height = round(height, 1)
            self._age = age

    @staticmethod
    def is_older_than_a_year(age: int) -> bool:
        return age > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    def show(self) -> None:
        self._stats.increment_show()
        print(
            f"{self._name}: "
            f"{self._height}cm, "
            f"{self._age} days old"
        )

    def grow(self, height: float = 1.0) -> None:
        self._height += height
        self._stats.increment_grow()

    def age(self, days: int = 1) -> None:
        if days < 0:
            return

        self._age += days
        self._stats.increment_age()

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def set_height(self, height: float) -> None:
        if self.validations(height=height):
            self._height = round(height, 1)

    def set_age(self, age: int) -> None:
        if self.validations(age=age):
            self._age = age

    def validations(
        self,
        height: float = None,
        age: int = None
    ) -> bool:
        if height is not None and height < 0:
            return False
        if age is not None and age < 0:
            return False
        return True

    def get_stats(self) -> "Plant.PlantStats":
        return self._stats


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        color: str
    ) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._blooming = False

    def show(self) -> None:
        super().show()
        print(f"Color: {self._color}")

        if self._blooming:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")

    def bloom(self) -> None:
        print(f"[asking the {self._name} to grow and bloom]")
        super().grow(8.0)
        self._blooming = True


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        color: str,
        seed_count: int
    ) -> None:
        super().__init__(name, height, age, color)
        self._seed_count = seed_count

        print("=== Seed")

    def show(self) -> None:
        super().show()
        if not self._blooming:
            print("Seeds: 0")
        else:
            print(f"Seeds: {self._seed_count}")

    def bloom(self) -> None:
        print(f"[asking the {self._name} to grow, age and bloom]")
        super().grow(30.0)
        super().age(20)
        self._blooming = True


class Tree(Plant):
    class TreeStats(Plant.PlantStats):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def increment_shade(self) -> None:
            self._shade_count += 1

        def display(self) -> None:
            super().display()
            print(f"{self._shade_count} shade")

    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter
        self._stats = Tree.TreeStats()
        print("=== Tree")

    def show(self) -> None:
        super().show()
        print(f"Trunk Diameter: {self._trunk_diameter}cm")

    def produce_shade(self) -> None:
        self._stats.increment_shade()

        print(f"[asking the {self._name} to produce shade]")
        print(
            f"Tree {self._name} now produces a shade of "
            f"{self._height}cm long and "
            f"{self._trunk_diameter}cm wide."
        )


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        harvest_season: str,
        nutritional_value: int = 0
    ) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

        print("=== Vegetable")

    def show(self) -> None:
        super().show()
        print(f"Harvest Season: {self._harvest_season.capitalize()}")
        print(f"Nutritional Value: {self._nutritional_value}")

    def grow(self) -> None:
        self.set_height(self._height + 2.1)
        self._stats.increment_grow()

    def age(self, days: int = 1) -> None:
        if days < 0:
            return

        print(
            f"[make {self._name} grow and age "
            f"for {days} days]"
        )

        for _ in range(days):
            self.set_age(self._age + 1)
            self._stats.increment_age()

            self.grow()
            self._nutritional_value += 1


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant._name}]")
    plant.get_stats().display()


def main() -> None:
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print("Is 30 days more than a year? -> ", end="")
    print(Plant.is_older_than_a_year(30))
    print("Is 400 days more than a year? -> ", end="")
    print(Plant.is_older_than_a_year(400))

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_statistics(rose)
    rose.bloom()
    rose.show()
    display_statistics(rose)

    print("")

    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_statistics(oak)
    oak.produce_shade()
    display_statistics(oak)

    print("")

    seed = Seed(
        "Sunflower",
        80.0,
        45,
        "yellow",
        42
    )
    seed.show()
    seed.bloom()
    seed.show()
    display_statistics(seed)
    print("")
    unknown_plant = Plant.create_anonymous()
    unknown_plant.show()
    display_statistics(unknown_plant)


if __name__ == "__main__":
    main()
