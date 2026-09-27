from ..elements import create_air
from alchemy.potions import healing_potion, strength_potion


def lead_to_gold() -> str:
    return f"Recipe transmuting Lead to Gold: brew '{create_air()}' and \
'{strength_potion()}' mixed with '{healing_potion()}'"
