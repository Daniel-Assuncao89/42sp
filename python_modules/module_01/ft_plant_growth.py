class Plant:
    def __init__(self, name: str, height: float, age: int, days: int) -> None:
        self.name = name
        self.height = round(height, 2)
        self.age = age
        self.days = days

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")

    def grow(self) -> None:
        self.height = round(self.height + 0.5785, 2)

    def age(self) -> None:
        self.age += 1

def ft_garden_data():
    print("=== Garden Plant Growth ===")
    flower = Plant("Flower", 25.45678, 23, 7)
    rose = Plant("Rose", 30, 15, 5)
    flower.show()

if __name__ == "__main__":
    ft_garden_data()