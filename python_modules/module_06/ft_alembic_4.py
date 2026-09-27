import alchemy


def main():
    print("=== Alembic 4 ===")
    print("Accessing the alchemy module using 'import alchemy'")
    print("Testing create_air:", alchemy.create_air())
    print("Now show that not all functions can be reached")
    print("This will raise an exception!")
    try:
        print("Testing the hidden create_earth: ", end="")
        print(alchemy.create_earth())
    except AttributeError:
        raise


if __name__ == "__main__":
    main()
