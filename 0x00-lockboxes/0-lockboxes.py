#!/usr/bin/python3
''' Program to solve the lockboxes problem, determining which can be opened '''


def canUnlockAll(boxes):
    ''' Returns True if all boxes can be opened, otherwise False '''
    availableKeys = [0]
    for x in availableKeys:
        for key in boxes[x]:
            if key not in availableKeys and key < len(boxes):
                availableKeys.append(key)

    x = 0
    while x < len(boxes):
        if x not in availableKeys:
            return False
        x += 1

    return True
