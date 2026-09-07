# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_archive_creation.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/07 19:24:10 by dassunca        #+#    #+#               #
#  Updated: 2026/09/07 20:55:10 by dassunca        ###   ########.fr        #
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
        
    except FileNotFoundError as e:
        print(f"Error opening file '{file_path}': {e}")
    except PermissionError as e:
        print(f"Error opening file '{file_path}': {e}")


if __name__ == "__main__":
    print("=== Cyber Archives Recovery ===")
    ancient_text()
