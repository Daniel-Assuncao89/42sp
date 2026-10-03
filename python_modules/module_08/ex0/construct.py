import sys
import os
import site


def global_construct() -> None:
    print(sys.base_prefix)


def venv_construct() -> None:
    print(sys.version_info)
    print("MATRIX STATUS: Welcome to the construct\n")
    print("Environment Path: ")
    print(sys.prefix)
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting the global system\n")
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
