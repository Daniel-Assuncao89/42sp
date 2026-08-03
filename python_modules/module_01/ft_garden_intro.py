def ft_garden_intro(name: str, height: float, age: int) -> None:
    print("=== Welcome to my Garden ===")
    print(f"Plant: {name}")
    print(f"Height: {height}")
    print(f"Age: {age} days")

if __name__ == "__main__":
    ft_garden_intro("Flower", 25, 23)