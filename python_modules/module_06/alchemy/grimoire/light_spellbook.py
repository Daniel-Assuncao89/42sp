from . import light_validator


def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    validate: str = light_validator.validate_ingredients(ingredients)
    if validate == "VALID":
        return f"Spell recorded: {spell_name} ({ingredients} - {validate})"
    else:
        return f"Spell '{spell_name}' not recorded, invalid ingredients"
