#!/usr/bin/python3
"""
Task 0
"""


def makeChange(coins, total):
    """Determine the fewest number of coins needed to make
    change for a given amount of money.
      coins (list): A list of coin values.
      total (int): The total amount of money to make change for.
      Return the fewest number of coins needed to make change for the
      given amount of money. If change cannot be made, return -1.
    """
    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        if total >= coin:
            count += total // coin
            total %= coin
    if total == 0:
        return count
    if total <= 0:
        return 0
    return -1
