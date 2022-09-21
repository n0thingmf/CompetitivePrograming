#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Point {
public:
    int x;
    int y;
};

std::vector<Point> convex_hull(const std::vector<Point>& V) {
    /*
    Build a convex hull of the given n points (i.e., build a convex polygon
    with a minimum perimeter that contains all the points).
    V is a set of points.
    Return a subset of V, which describes a convex hull.
    */
    std::vector<Point> result;

    // YOUR CODE HERE

    return result;
}

int main() {
    int n;
    std::cin >> n;
    int m;
    std::vector<Point> V(n);
    std::vector<Point> p;
    std::vector<int> V_coord(2 * n);
    for (int &item : V_coord) {
        std::cin >> item;
    }
    for (int i = 0; i < n; ++i) {
        V[i].x = V_coord[2 * i];
        V[i].y = V_coord[2 * i + 1];
    }
    p = convex_hull(V);
    std::cout << m << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << p[i].x << ' ' << p[i].y << ' ' << " ";
    }
}
