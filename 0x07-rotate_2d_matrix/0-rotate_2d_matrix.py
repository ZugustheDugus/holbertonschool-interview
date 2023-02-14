#!/usr/bin/python3
"""Rotate 2D Matrix Module"""


def rotate_2d_matrix(matrix):
    """Function which Rotates a 2D Matrix in place
    """

    length = len(matrix)
    result = [[0] * length for _ in range(length)]
    for i in range(length):
        for j in range(length):
            result[j][length-1-i] = matrix[i][j]
    matrix[:] = result[:]
