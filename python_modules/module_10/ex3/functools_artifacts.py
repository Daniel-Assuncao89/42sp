import operator
from collections.abc import Callable
from functools import lru_cache, partial, reduce, singledispatch
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    """Reduce a list of spell powers with the chosen operation."""
    operations: dict[str, Callable[[int, int], int]] = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max,
        "min": min,
    }
    if operation not in operations:
        raise ValueError(f"Unknown operation: {operation}")
    if not spells:
        return 0
    return reduce(operations[operation], spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    """Create 3 specialised enchantments with power=50 pre-filled."""
    return {
        "fire_enchant": partial(base_enchantment, 50, "fire"),
        "ice_enchant": partial(base_enchantment, 50, "ice"),
        "lightning_enchant": partial(base_enchantment, 50, "lightning"),
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    """Return the nth Fibonacci number (cached)."""
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    """Return a singledispatch function that reacts to the spell type."""
    @singledispatch
    def cast(spell: Any) -> str:
        return "Unknown spell type"

    @cast.register(int)
    def _(spell: int) -> str:
        return f"{spell} damage"

    @cast.register(str)
    def _(spell: str) -> str:
        return spell

    @cast.register(list)
    def _(spell: list) -> str:
        return f"{len(spell)} spells"

    return cast


if __name__ == "__main__":
    powers = [10, 20, 30, 40]
    print("Testing spell reducer...")
    print("Sum:", spell_reducer(powers, "add"))
    print("Product:", spell_reducer(powers, "multiply"))
    print("Max:", spell_reducer(powers, "max"))
    print("Min:", spell_reducer(powers, "min"))
    print("Empty:", spell_reducer([], "add"))
    try:
        spell_reducer(powers, "divide")
    except ValueError as error:
        print("Error handled:", error)

    print("\nTesting partial enchanter...")

    def enchant(power: int, element: str, target: str) -> str:
        return f"{element} enchantment ({power}) on {target}"

    enchants = partial_enchanter(enchant)
    for name, func in enchants.items():
        print(f"{name}: {func('Sword')}")

    print("\nTesting memoized fibonacci...")
    for n in (0, 1, 10, 15):
        print(f"Fib({n}): {memoized_fibonacci(n)}")
    print(memoized_fibonacci.cache_info())

    print("\nTesting spell dispatcher...")
    dispatch = spell_dispatcher()
    print("Damage spell:", dispatch(42))
    print("Enchantment:", dispatch("fireball"))
    print("Multi-cast:", dispatch(["a", "b", "c"]))
    print(dispatch(3.14))
