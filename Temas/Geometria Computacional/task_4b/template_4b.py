import sys
import typing as tp


class Point:
    x: int
    y: int


def list_all_triangles(polygon: tp.List[Point]) -> tp.List[tp.List[Point]]:
    """
    Triangulate a~given polygon by the ear-cutting algorithm.
    Polygon is given as an array of its vertices.
    Return an array of triples (A, B, C) for every triangle ABC.
    """
    list_of_triangles: tp.List[tp.List[Point]]

    # YOUR CODE HERE

    return list_of_triangles


if __name__ == '__main__':
    n = int(input())
    V: tp.List[Point] = [Point() for _ in range(n)]
    V_coord = list(map(int, input().split()))
    for i in range(0, n):
        V[i].x = V_coord[2 * i]
        V[i].y = V_coord[2 * i + 1]

    triangulation: tp.List[tp.List[Point]]
    triangulation = list_all_triangles(V)
    number_of_triags = len(triangulation)
    print(number_of_triags)
    for i in range(0, number_of_triags):
        print(triangulation[i][0].x, triangulation[i][0].y, triangulation[i][1].x, triangulation[i][1].y, triangulation[i][2].x, triangulation[i][2].y)


