from . import light_spellbook


def validate_ingredients(ingredients: str) -> str:
    allowed_ingredients = light_spellbook.light_spell_allowed_ingredients()
    for ingridient in allowed_ingredients:
        if ingridient in ingredients.lower():
            return "VALID"
    return "INVALID"
