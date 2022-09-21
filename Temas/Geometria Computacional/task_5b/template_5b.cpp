#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Point {
public:
    int x;
    int y;
};

std::vector<int> count_inside_points(const std::vector<Point>& S, const std::vector<std::vector<Point>>& queries) {
    /*
    Given a set of points S and a set of query rectangles with sides parallel to the axes.
    Compute the number of points from S lying inside each rectangle.
    Any of the two sides of the rectangle may have zero length
    (in such a case, the rectangle degenerates to a segment or a point).
    Return array of answers on queries.
    */
    std::vector<int> results;

    // YOUR CODE HERE

    return results;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);
    std::vector<int> points_coord(2 * n);
    for (int &item : points_coord) {
        std::cin >> item;
    }
    for (int i = 0; i < n; ++i) {
        points[i].x = points_coord[2 * i];
        points[i].y = points_coord[2 * i + 1];
    }
    int q;
    std::cin >> q;
    std::vector<std::vector<Point>> queries(q);
    for (int i = 0; i < q; ++i) {
        std::vector<Point> rectangle(2);
        std::cin >> rectangle[0].x >> rectangle[0].y >> rectangle[1].x >> rectangle[1].y;
        queries[i] = rectangle;
    }
    std::vector<int> result;
    result = count_inside_points(points, queries);
    for (int i = 0; i < q; ++i) {
        std::cout << result[i] << std::endl;
    }
}
