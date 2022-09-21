import sys
import typing as tp


class Point:
    x: int
    y: int


def determine_polygons_intersection(V: tp.List[Point], W: tp.List[Point]) -> tp.List[Point]:
    """
    Given 2 convex polygons, it is required to find their intersection.
    Two polygons intersect nondegenerately: the intersection of two edges occurs
    at a single point and forms a convex polygon. The intersection may also be absent,
    in this case output 0.
    V and W are given as lists of vertices in counterclockwise order
    Return a list of vertices of their intersection.
    """
    result: tp.List[Point] = list()

    # YOUR CODE HERE

    return result


if __name__ == '__main__':
    n = int(input())
    V: tp.List[Point] = [Point() for _ in range(n)]
    V_coord = list(map(int, input().split()))
    for i in range(0, n):
        V[i].x = V_coord[2 * i]
        V[i].y = V_coord[2 * i + 1]

    m = int(input())
    W: tp.List[Point] = [Point() for _ in range(m)]
    W_coord = list(map(int, input().split()))
    for i in range(0, m):
        W[i].x = V_coord[2 * i]
        W[i].y = V_coord[2 * i + 1]

    res = determine_polygons_intersection(V, W)
    res_size = len(res)
    print(res_size)
    for i in range(0, res_size):
        print(res[i].x, res[i].y, " ", end='')


