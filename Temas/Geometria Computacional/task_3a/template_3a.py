import sys
import typing as tp


def determine_relative_position(A_x: int, A_y: int, B_x: int, B_y: int, C_x: int, C_y: int, D_x: int, D_y: int) -> str:
    """
    Determine relative position of segments AB and CD.
    8 args of this function are coordinates of A, B, C, D
    Return one message of one of the following formats:
    No common points.
    The intersection point is (E_x, E_y).
    A common segment of non-zero length.
    """

    # YOUR CODE HERE

    return result


if __name__ == '__main__':
    A_x, A_y, B_x, B_y = map(int, input().split())
    C_x, C_y, D_x, D_y = map(int, input().split())
    result = determine_relative_position(A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y)
    print(result)

