# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_stream_management.py                           :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/11 14:29:55 by dassunca        #+#    #+#               #
#  Updated: 2026/09/12 19:42:54 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys
import typing


def terminal_write(message: str) -> None:
    sys.stdout.write(message)
    sys.stdout.flush()


def args_validation() -> bool:
    if len(sys.argv) != 2:
        sys.stdout.write("Usage: ft_ancient_text.py <file>\n")
        return False
    return True


def file_validation(file_path: str, mode: str = 'r') -> bool:
    try:
        file: typing.IO = open(file_path, 'r')
        print("ta passando?")
        file.close()
        return True
    except FileNotFoundError as e:
        sys.stderr.write(f"[STDERR] Error opening file '{file_path}': {e}\n")
    except PermissionError as e:
        sys.stderr.write(f"[STDERR] Error opening file '{file_path}': {e}\n")
    return False


def ancient_text() -> None:
    if not args_validation():
        return

    file_path: str = sys.argv[1]
    terminal_write(f"Acessing file '{file_path}'\n")
    if not file_validation(file_path):
        return
    terminal_write("---\n\n")
    file: typing.IO = open(file_path, 'r')
    content: str = file.readlines()
    for line in content:
        terminal_write(line)
    terminal_write("\n---")
    file.close()
    terminal_write(f"File '{file_path}' closed. \n")
    terminal_write("Transform data:\n")
    terminal_write("---\n")
    new_content: list[str] = [
        (line.replace('\n', '#\n')) for line in content
        ]
    for line in new_content:
        terminal_write(line)
    terminal_write("Enter new file name (or empty): ")
    save_destination: str = sys.stdin.readline().strip()
    file_bool: bool = file_validation(save_destination, mode='w')
    if not save_destination or not file_bool:
        terminal_write("Data not saved.")
        return
    terminal_write(f"Saving data to '{save_destination}'\n")
    new_file: typing.IO = open(save_destination, 'w')
    new_file.writelines(new_content)
    new_file.close()
    terminal_write(f"Data saved in file '{save_destination}'")


if __name__ == "__main__":
    terminal_write("=== Cyber Archives Recovery & Preservation ===\n")
    ancient_text()
