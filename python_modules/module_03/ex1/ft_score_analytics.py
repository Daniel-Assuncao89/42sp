# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_score_analytics.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: dassunca <dassunca@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/08/20 13:02:53 by dassunca        #+#    #+#               #
#  Updated: 2026/08/20 13:35:57 by dassunca        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys


def handle_excepts(args: list) -> list:
    score = []
    for arg in args:
        if arg == args[0]:
            continue
        try:
            score.append(int(arg))
        except Exception:
            print(f"Invalid parameter: '{arg}'")
    return score


def score_analytics() -> None:
    print("=== Player Score Analytics ===")
    terminal_args = sys.argv
    scores_processed = handle_excepts(terminal_args)
    players = len(scores_processed)
    if scores_processed:
        avarage_score = sum(scores_processed) / players
        score_range = max(scores_processed) - min(scores_processed)
        print(f"Score processed: {scores_processed}")
        print(f"Total players: {players}")
        print(f"Total score: {sum(scores_processed)}")
        print(f"Avarage score: {avarage_score}")
        print(f"High score: {max(scores_processed)}")
        print(f"Low score: {min(scores_processed)}")
        print(f"Score range: {score_range}")
    else:
        print("No scores provided. \
Usage: python3 ft_score_analytics <score1> <score2> ...")


if __name__ == "__main__":
    score_analytics()
