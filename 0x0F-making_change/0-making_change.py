#!/usr/bin/python3
"""
Task 0
"""

def makeChange(coins, total):
    '''
    coins: A list of values representing the coins you have.
    total: The total you have to make change for.
    Returns a list of the fewest coins possible to equal the total needed,
    or -1 if not possible.
    '''
    if (total < 1):
        return 0
    changeMade = [0] * (total + 1)
    coins.sort(reverse=True)
    for coin in coins:
        for x in range(coin, total + 1):
            if (changeMade[x - coin]):
                if (changeMade[x]):
                    changeMade[x] = min(changeMade[x],
                                        changeMade[x - coin] + 1)
                else:
                    changeMade[x] = changeMade[x - coin] + 1
            elif (not x % coin):
                changeMade[x] += 1
    return changeMade[total] if changeMade[total] else -1
