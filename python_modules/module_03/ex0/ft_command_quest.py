# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_command_quest.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/20 12:17:48 by dassunca        #+#    #+#               #
#  Updated: 2026/08/20 13:02:32 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys


def command_quest() -> None:
    print("=== Command Quest ===")
    index = 1
    splited_args = sys.argv
    program_name = splited_args[0].split('/', -1)[2]
    len_args = len(splited_args)
    print(f"Program name: {program_name}")
    if len_args == 1:
        print("No arguments provided!")
    else:
        print("Arguments received: ", len_args - 1)
        while index < len_args:
            print(f"Argument {index}: {splited_args[index]}")
            index += 1
    print(f"Total arguments: {len_args}\n")


if __name__ == "__main__":
    command_quest()
