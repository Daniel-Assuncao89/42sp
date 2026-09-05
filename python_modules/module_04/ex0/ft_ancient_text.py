# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_ancient_text.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/03 18:50:37 by dassunca        #+#    #+#               #
#  Updated: 2026/09/05 20:07:34 by dassunca        ###   ########.fr        #
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
        print(f"Acessing file '{file_path}'\n")
        file: typing.IO = open(file_path, 'r')
        content: str = file.read()
        print("---\n\n")
        print(content)
        print("---")
        file.close()
        print(f"File '{file_path}' closed.")
    except FileNotFoundError as e:
        print(f"Error opening file '{file_path}': {e}")
    except PermissionError as e:
        print(f"Permission denied for file '{file_path}': {e}")


if __name__ == "__main__":
    print("=== Cyber Archives Recovery ===")
    ancient_text()
