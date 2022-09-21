import sys
import typing as tp


class Point:
    x: int
    y: int


def convex_hull(V: tp.List[Point]) -> tp.List[Point]:
    """
    Build a convex hull of the given n points (i.e., build a convex polygon
    with a minimum perimeter that contains all the points).
    V is a set of points.
    Return a subset of V, which describes a convex hull.
    """
    result: tp.List[Point] = list()

    # YOUR CODE HERE

    return result


if __name__ == '__main__':
    n = int(input())
    V: tp.List[Point] = [Point() for _ in range(n)]
    p: tp.List[Point] = list()
    V_coord = list(map(int, input().split()))
    for i in range(0, n):
        V[i].x = V_coord[2 * i]
        V[i].y = V_coord[2 * i + 1]

    p = convex_hull(V)
    print(m)
    for i in range(0, m):
        print(p[i].x, p[i].y, " ", end='')


