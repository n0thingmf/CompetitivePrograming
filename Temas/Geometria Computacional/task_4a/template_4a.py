import sys
import typing as tp


class Point:
    x: int
    y: int


def determine_AB_location(V: tp.List[Point], a: int, b: int) -> str:
    """
    Given a simple polygon and its diagonal,
    check, whether it is external, internal, or intersects the side.
    V is an array of vertices of a polygon, a and b are indices of considered vertices.
    Return one of the following messages: {"INTERSECT, "INTERNAL", "EXTERNAL"}.
    """

    # YOUR CODE HERE


if __name__ == '__main__':
    n = int(input())
    V: tp.List[Point] = [Point() for _ in range(n)]
    V_coord = list(map(int, input().split()))
    for i in range(0, n):
        V[i].x = V_coord[2 * i]
        V[i].y = V_coord[2 * i + 1]

    number_of_diags: int

    # YOUR CODE HERE

    print(number_of_diags)
    for i in range(0, len(V)):
        for j in range(i + 2, len(V)):
            # YOUR CODE HERE

            result = determine_AB_location(V, V[i], V[j], i)
            print(V[i].x, V[i].y, V[j].x, V[j].y, result)
