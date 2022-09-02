#!/usr/bin/python3
"""Program to determine if a series of lockboxes can be opened"""

def join(T,R):
    """Function which joins two halves of a list"""
    res =[]
    for e in R:
        res += T[e]


def canUnlockAll(boxes):
    """function to count unlocked lockboxes"""
    index = 0
    total = list(set(boxes[0])| {0})
    added = True
    while added:
        added = False
    for j in join(boxes,total[index:]):
        if j not in total:
            total.append(j)
            index +=1
            added= True
    print(total)

    return len(total)==len(boxes)
