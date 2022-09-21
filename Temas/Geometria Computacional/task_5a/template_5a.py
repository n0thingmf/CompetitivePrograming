import sys
import typing as tp


class Point:
    x: int
    y: int


def determine_nearest_point(S: tp.List[int], Q: tp.List[int]) -> tp.List[int]:
    """
    Given a set S of points on a line and a set Q of query points,
    find the closest neighbor of the query point,
    i.e., a point from S with the minimum distance to the query point.
    Return array of answers on the queries
    """
    results: tp.List[int] = list()

    # YOUR CODE HERE

    return results


if __name__ == '__main__':
    n = int(input())
    line_points = list(map(int, input().split()))
    m = int(input())
    queries: tp.List[int] = [int() for _ in range(m)]
    for i in range(0, m):
        queries[i] = int(input())

    result = determine_nearest_point(line_points, queries)
    for i in range(0, m):
        print(result[i])


