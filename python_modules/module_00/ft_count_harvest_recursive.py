def ft_count_harvest_recursive(days=None, index=None):
    if days is None:
        print("Days until harvest: ", end="")
        days = int(input())
        index = 1;
    elif days > 0:
        print(f"Day {index}")
        ft_count_harvest_recursive(days - 1, index + 1)
    elif days == 0:
        print("Harvest time!")