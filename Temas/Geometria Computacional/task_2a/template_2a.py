import sys
import typing as tp


class Point:
    x: int
    y: int


def is_convex(V: tp.List[Point]) -> tp.List[Point]:
    """
    Given a simple polygon V1 V2 ... Vn, determine whether it is convex.
    V: vertices of polygon, vertices are listed in counterclockwise order
    return: CONVEX, if polygon is convex. NOT_CONVEX, if polygon is not convex.
    """

    # YOUR CODE HERE

    return result


if __name__ == '__main__':
    n = int(input())
    V: tp.List[Point] = [Point() for _ in range(n)]
    V_coord = list(map(int, input().split()))
    for i in range(0, n):
        V[i].x = V_coord[2 * i]
        V[i].y = V_coord[2 * i + 1]

    result = is_convex(V)
    print(result)

