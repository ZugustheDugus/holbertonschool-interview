#!/usr/bin/python3
''' Task 0 '''


def minOperations(n):
    ''' Finds fewest ops needed to get n 
    characters to a file '''
    if n < 2 or n is None:
        return 0
    noOps = 0
    while n > 1:
        max = n + 1
        for x in range(2, max):
            if n % x == 0:
                n = n // x
                noOps += x
                break

    return noOps
