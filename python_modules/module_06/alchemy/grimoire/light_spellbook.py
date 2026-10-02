def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    if ingredients in light_spell_allowed_ingredients():
        return f"Spell '{spell_name}' recorded"
    else:
        return f"Spell '{spell_name}' not recorded, invalid ingredients"
