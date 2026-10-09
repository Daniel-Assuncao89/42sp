import sys
import site


def global_construct() -> None:
    print("MATRIX STATUS: You're still plugged in\n")
    print("Current Python: ", end="")
    print(sys.base_prefix)
    print("Virtual Enviroment: None detected\n")
    print("WARNING: You're in the global enviroment!")
    print("The machines can see everything you install.\n")
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print("matrix_env\\Scripts\\activate # On Windows\n")
    print("Then run this program again.")


def venv_construct() -> None:
    print("MATRIX STATUS: Welcome to the construct\n")
    print("Current Python: ", end="")
    print(sys.executable)
    print("Virtual Environment: ", end="")
    print(sys.prefix.split("/")[-1])
    print("Environment Path: ", end="")
    print(sys.prefix, "\n")
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting")
    print("the global system\n")
    print("Package installation path:")
    print(site.getsitepackages()[0])
    # print(os.environ)


def chose_construct() -> None:
    args_env: list[str] = sys.prefix.split('/')
    if "matrix_env" in args_env:
        venv_construct()
    else:
        global_construct()


if __name__ == "__main__":
    chose_construct()
