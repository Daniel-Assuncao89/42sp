def ft_count_harvest_iterative() -> None:
    print("Days until harvest: ", end="")
    days = int(input())
    for i in range(days):
        print(f"Day {i + 1}")
    print("Harvest time!")