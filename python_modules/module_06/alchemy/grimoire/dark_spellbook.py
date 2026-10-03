from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    validate: str = validate_ingredients(ingredients)
    if validate == "VALID":
        return f"Spell '{spell_name}' recorded"
    else:
        return f"Spell '{spell_name}' not recorded, invalid ingredients"
