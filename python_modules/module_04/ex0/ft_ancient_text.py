# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_ancient_text.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/03 18:50:37 by dassunca        #+#    #+#               #
#  Updated: 2026/09/03 19:49:46 by dassunca        ###   ########.fr        #
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
        print(file_path)
        print(open(file_path, "r"))
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ancient_text()
