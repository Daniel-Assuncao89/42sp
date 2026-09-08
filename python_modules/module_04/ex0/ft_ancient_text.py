# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_ancient_text.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/03 18:50:37 by dassunca        #+#    #+#               #
#  Updated: 2026/09/07 20:54:26 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys
import typing


def ancient_text() -> None:
    if len(sys.argv) == 1:
        print("Usage: ft_ancient_text.py <file>\n")
        return
    try:
        file_path: str = sys.argv[1]
        print(f"Acessing file '{file_path}'")
        file: typing.IO = open(file_path, 'r')
        content: str = file.read()
        print("---\n")
        print(content)
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
