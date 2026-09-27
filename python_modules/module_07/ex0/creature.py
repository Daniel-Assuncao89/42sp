import abc
import typing


class Creature(abc.ABC):
    def _init__(self, name: str, type: str) -> None:
        self.name = name
        self.type = type

    @abc.abstractmethod
    def attack(self, attack: str) -> None:
        pass

    def describe(self) -> str:
        return f"{self.name} is a {self.type}"


class Flameling(Creature):
    def attack(self, attack) -> str:
        return f"{self.name} uses Ember!"


class Pyrodon(Creature):
    def attack(self, attack) -> str:
        return f"{self.name} uses Flamethrower!"


class Aquabub(Creature):
    def attack(self, attack) -> str:
        return f"{self.name} uses Ember!"


class Torragon(Creature):
    def attack(self, attack) -> str:
        return f"{self.name} uses Flamethrower!"


class CreatureFactory(abc.ABC):
    @abc.abstractmethod
    def create_base(self) -> Creature:
        pass

    @abc.abstractmethod
    def create_evolved(self) -> Creature:
        pass


class FlameFactory(CreatureFactory):
    def create_base(self, name: str, type: str) -> Creature:
        return Creature(self, name, type)

    def create_evolved(self):
        return super().create_evolved()


class AquaFactory(CreatureFactory):
    def create_base(self, name: str, type: str) -> Creature:
        return Creature(self, name, type)

    def create_evolved(self):
        return super().create_evolved()