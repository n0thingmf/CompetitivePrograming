#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Point {
public:
    int x;
    int y;
};

std::vector<int> determine_nearest_point(const std::vector<int>& S, const std::vector<int>& Q) {
    /*
    Given a set S of points on a line and a set Q of query points,
    find the closest neighbor of the query point,
    i.e., a point from S with the minimum distance to the query point.
    Return array of answers on the queries
    */
    std::vector<int> results;

    // YOUR CODE HERE

    return results;
}

int main() {
    int n;
    std::cin >> n;
    int m;
    std::vector<int> line_points(n);
    for (int &item : line_points) {
        std::cin >> item;
    }
    std::cin >> m;
    std::vector<int> queries(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> queries[i];
    }
    std::vector<int> result;
    result = determine_nearest_point(line_points, queries);
    for (int i = 0; i < m; ++i) {
        std::cout << result[i] << std::endl;
    }
}
