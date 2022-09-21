import sys
import typing as tp


class Point:
    x: int
    y: int


def count_inside_points(S: tp.List[Point], queries: tp.List[tp.List[Point]]) -> tp.List[int]:
    """
    Given a set of points S and a set of query rectangles with sides parallel to the axes.
    Compute the number of points from S lying inside each rectangle.
    Any of the two sides of the rectangle may have zero length
    (in such a case, the rectangle degenerates to a segment or a point).
    Return array of answers on queries.
    """
    results: tp.List[int] = list()

    # YOUR CODE HERE

    return results


if __name__ == '__main__':
    n = int(input())
    points: tp.List[Point] = [Point() for _ in range(n)]
    points_coord = list(map(int, input().split()))
    for i in range(0, n):
        points[i].x = points_coord[2 * i]
        points[i].y = points_coord[2 * i + 1]

    q = int(input())
    queries: tp.List[tp.List[Point]] = [tp.List[Point]() for _ in range(q)]
    for i in range(0, q):
        rectangle: tp.List[Point] = [Point() for _ in range(2)]
        rectangle[0].x, rectangle[0].y, rectangle[1].x, rectangle[1].y = map(int, input().split())
        queries[i] = rectangle

    result = count_inside_points(points, queries)
    for i in range(0, q):
        print(result[i])


