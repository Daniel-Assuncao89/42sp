import inspect
import time
from collections.abc import Callable
from functools import wraps
from typing import Any


def spell_timer(func: Callable) -> Callable:
    """Print the casting time of the decorated function."""
    @wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        start = time.perf_counter()
        result = func(*args, **kwargs)
        elapsed = time.perf_counter() - start
        print(f"Spell completed in {elapsed:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    """Decorator factory: block calls whose 'power' < min_power."""
    def decorator(func: Callable) -> Callable:
        signature = inspect.signature(func)

        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            bound = signature.bind(*args, **kwargs)
            if bound.arguments["power"] >= min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    """Decorator factory: retry the function when it raises."""
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print("Spell failed, retrying... "
                              f"(attempt {attempt}/{max_attempts})")
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return (isinstance(name, str) and len(name) >= 3
                and all(c.isalpha() or c.isspace() for c in name))

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


if __name__ == "__main__":
    print("Testing spell timer...")

    @spell_timer
    def fireball() -> str:
        time.sleep(0.1)
        return "Fireball cast!"

    print("Result:", fireball())

    print("\nTesting retrying spell...")

    @retry_spell(max_attempts=3)
    def unstable_spell() -> str:
        raise RuntimeError("Waaaaaaagh spelled !")

    print(unstable_spell())

    print("\nTesting MageGuild...")
    guild = MageGuild()
    print(MageGuild.validate_mage_name("Gandalf"))
    print(MageGuild.validate_mage_name("X1"))
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Spark", 5))
