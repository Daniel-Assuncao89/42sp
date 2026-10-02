def validate_ingredients(ingredients: str) -> str:
    allowed_ingredients = ["earth", "air", "fire", "water"]
    if ingredients in allowed_ingredients:
        return "VALID"
    return "INVALID"
