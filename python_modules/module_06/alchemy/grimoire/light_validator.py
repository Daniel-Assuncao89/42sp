def validate_ingredients(ingredients: str) -> bool:
    allowed_ingredients = ["earth", "air", "fire", "water"]
    return ingredients in allowed_ingredients
