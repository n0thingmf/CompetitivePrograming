import sys
import typing as tp


def determine_point_position(A_x: int, A_y: int, B_x: int, B_y: int, p_x: int, p_y: int) -> str:
    """
    Given a vector AB (starting at point A and ending at point B) and point p on the plane,
    determine the relative position of each point with respect to the vector:
    point lies either on the right side, or on the left side,
    or on the vector, or on the continuation of the vector.
    A_x, A_y, B_x, B_y are coordinates of A and B respectively.
    p_x, p_y - coordinates of p.
    return: one of {"LEFT", "RIGHT", "ON_SEGMENT", "ON_LINE"}
    """

    # YOUR CODE HERE

    return result


if __name__ == '__main__':
    A_x, A_y, B_x, B_y = map(int, input().split())
    n = int(input())
    p_x: tp.List[int] = [int() for _ in range(n)]
    p_y: tp.List[int] = [int() for _ in range(n)]
    for i in range(0, n):
        p_x[i], p_y[i] = map(int, input().split())

    for i in range(0, n):
        result = determine_point_position(A_x, A_y, B_x, B_y, p_x[i], p_y[i])
        print(result)


