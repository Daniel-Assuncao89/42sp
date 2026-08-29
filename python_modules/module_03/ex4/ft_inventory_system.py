# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_inventory_system.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/25 14:34:27 by dassunca        #+#    #+#               #
#  Updated: 2026/08/28 20:08:12 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys


def parser() -> dict:
    user_args = sys.argv
    dict_values: dict = {}
    parsed_values: list = [args
                           for args in user_args[1:]
                           if args.find(':') > 0]
    duplicated: set = set()
    # Valores invalidos
    invalid_values: list = [not_parsed
                            for not_parsed in user_args[1:]
                            if not_parsed not in parsed_values]
    # Redundantes
    for value in parsed_values:
        value_key = value.partition(':')[0]
        if value_key in duplicated:
            print(
                f"Redundant item '{value_key}' - discarding"
                )
            parsed_values.remove(value)
        else:
            duplicated.add(value_key)

    for value in invalid_values:
        print(f"Error - invalid parameter '{value}'")

    # Checar se é digito no value. se não exibir o erro
    for value in parsed_values:
        try:
            value_split = value.partition(':')
            dict_values[value_split[0]] = int(value_split[2])
        except ValueError as e:
            print(f"Quantity error for 'key': {e}")
    return dict_values


def inventory_system() -> None:
    print("=== Inventory System Analysis ===")
    dict_values: dict = parser()
    total_items: int = len(dict_values)
    total_quantity = sum(dict_values.values())
    item_max_qtd: int = 0
    item_max: str = ""
    item_min_qtd: int = 99
    item_min: str = ""

    print("Got inventory: ", dict_values)
    print("Item list: ", list(dict_values.keys()))
    print(f"Total quantity of the {total_items} items: {total_quantity}")
    if len(sys.argv) > 1:
        for item, qtd in dict_values.items():
            if qtd > item_max_qtd:
                item_max_qtd, item_max = qtd, item
            if item_min_qtd > qtd:
                item_min_qtd, item_min = qtd, item
            item_perc = (qtd/total_quantity)*100
            print(f"Item {item} represents {item_perc:.1f}%")
        print(f"Item most abundant: {item_max}", end=" ")
        print(f"with quantity {item_max_qtd}")
        print(f"Item least abundant: {item_min}", end=" ")
        print(f"with quantity {item_min_qtd}")
        dict_values.update({"magic_item": 1})
        print(f"Updated inventory: {dict_values}")


if __name__ == "__main__":
    inventory_system()
