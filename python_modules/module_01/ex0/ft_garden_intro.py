# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_intro.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42sp.org.br>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/04 16:14:00 by dassunca        #+#    #+#               #
#  Updated: 2026/08/11 13:45:16 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_garden_intro(name: str, height: float, age: int) -> None:
    print("=== Welcome to my Garden ===")
    print(f"Plant: {name}")
    print(f"Height: {height}cm")
    print(f"Age: {age} days")
    print("=== End of Program ===")


if __name__ == "__main__":
    ft_garden_intro("Rose", 25, 23)
