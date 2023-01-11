#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1 as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.
    """
    if not walls or len(walls) < 3:
        return 0
    water = 0
    for i in range(1, len(walls) - 1):
        left = max(walls[:i])
        # print("left: ", left)
        right = max(walls[i + 1:])
        # print("right: ", right)
        water += max(0, min(left, right) - walls[i])
        # print("water: ", water)
    return water