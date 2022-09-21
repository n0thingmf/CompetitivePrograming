import sys
import typing as tp


def determine_point_position(A_x: int, A_y: int, B_x: int, B_y: int, C_x: int, C_y: int, p_x: int, p_y: int) -> str:
    """
    Given a triangle ABC and n points p1, p2, ... , pn on the plane, determine for each point
    whether it is inside, outside, or on the border of the triangle.
    A_x, A_y, B_x, B_y, C_x, C_y are coordinates of A, B and C respectively.
    p_x, p_y - coordinates of p.
    return: one of {"INSIDE", "OUTSIDE", "BORDER"}
    """

    # YOUR CODE HERE

    return result


if __name__ == '__main__':
    A_x, A_y, B_x, B_y, C_x, C_y = map(int, input().split())
    n: int
    n = int(input())
    p_x: tp.List[int] = [int() for _ in range(n)]
    p_y: tp.List[int] = [int() for _ in range(n)]
    for i in range(0, n):
        p_x[i], p_y[i] = map(int, input().split())

    for i in range(0, n):
        result = determine_point_position(A_x, A_y, B_x, B_y, C_x, C_y, p_x[i], p_y[i])
        print(result)


