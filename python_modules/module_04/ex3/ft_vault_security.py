# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_vault_security.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/09/12 19:48:12 by dassunca        #+#    #+#               #
#  Updated: 2026/09/13 15:29:19 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def secure_arquive(file_name: str, mode: str = 'r') -> tuple[bool, str]:
    try:
        with open(file_name, mode) as file:
            if mode == 'r':
                return (True, file.read())
            if mode == 'w':
                file.write(
                    "[FRAGMENT 001] Digital preservation protocols \
established 2087\n")
                file.write(
                    "[FRAGMENT 002] Knowledge must survive the entropy \
wars\n")
                file.write("[FRAGMENT 003] Every byte saved is a victory \
against oblivion\n")
                return (True, "Content successfully written to file.")
    except FileNotFoundError as e:
        return (False, f"{e}")
    except PermissionError as e:
        return (False, f"{e}")


if __name__ == "__main__":
    print("Using 'secure_arquive' to read from a nonexistent file:")
    print(secure_arquive("/not/existing/file"))

    print("\nUsing 'secure_arquive' to read from a inaccessible file:")
    print(secure_arquive("file_denied.txt"))

    print("\nUsing 'secure_arquive' to read from a regural file:")
    print(secure_arquive("file_denied.txt"))

    print("\nUsing 'secure_arquive' to write previous content to a file:")
    print(secure_arquive("file_denied.txt", mode='w'))
