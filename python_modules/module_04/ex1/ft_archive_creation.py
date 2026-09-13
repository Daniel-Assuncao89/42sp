# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_archive_creation.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/07 19:24:10 by dassunca        #+#    #+#               #
#  Updated: 2026/09/11 14:20:57 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys
import typing


def ancient_text() -> None:
    if len(sys.argv) == 1:
        print("Usage: ft_ancient_text.py <file>")
        return
    try:
        file_path: str = sys.argv[1]
        print(f"Acessing file '{file_path}'")
        print("---\n")
        file: typing.IO = open(file_path, 'r')
        content: str = file.readlines()
        for line in content:
            print(line, end="")
        print("\n---")
        file.close()
        print(f"File '{file_path}' closed.")
        print("Transform data:")
        print("---\n")
        new_content: list[str] = [
            (line.replace('\n', '#\n')) for line in content
            ]
        for line in new_content:
            print(line, end="")
        save_destination: str = input("Enter new file name (or empty): ")
        if not save_destination:
            print("Not saving data.")
            return
        print(f"Saving data to '{save_destination}'")
        new_file: typing.IO = open(save_destination, 'w')
        new_file.writelines(new_content)
        new_file.close()
        print(f"Data saved in file '{save_destination}'")
    except FileNotFoundError as e:
        print(f"Error opening file '{file_path}': {e}")
    except PermissionError as e:
        print(f"Error opening file '{file_path}': {e}")


if __name__ == "__main__":
    print("=== Cyber Archives Recovery ===")
    ancient_text()
