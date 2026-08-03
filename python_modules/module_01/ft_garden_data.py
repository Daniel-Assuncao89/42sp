class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print("=== Garden Plant Registry ===")
        print(f"{self.name}: {self.height}cm, {self.age} days old")

def ft_garden_data():
    plant = Plant("Flower", 25, 23)
    plant.show()

if __name__ == "__main__":
    ft_garden_data()