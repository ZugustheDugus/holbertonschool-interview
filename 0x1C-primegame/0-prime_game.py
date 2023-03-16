#!/usr/bin/python3
''' Prime Game Problem '''


def isWinner(x, nums):
    ''' Determines who the winner of each game is, Maria or Ben.
    Maria always goes first, and both players play
    100% without error '''

    if not nums or x < 1:
        return None
    Maria = 0
    Ben = 0
    for i in range(x):
        nums = [num for num in nums if num % 2 == 1]
        if (len(nums) == 0):
            return None
        if (len(nums) % 2 == 0):
            Maria += 1
        else:
            Ben += 1
    if (Maria > Ben):
        return "Maria"
    elif (Ben > Maria):
        return "Ben"
    else:
        return None
