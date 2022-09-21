#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Point {
public:
    int x;
    int y;
};

std::vector<Point> determine_polygons_intersection(const std::vector<Point>& V, const std::vector<Point>& W) {
    /*
    Given 2 convex polygons, it is required to find their intersection.
    Two polygons intersect nondegenerately: the intersection of two edges occurs
    at a single point and forms a convex polygon. The intersection may also be absent,
    in this case output 0.
    V and W are given as lists of vertices in counterclockwise order
    Return a list of vertices of their intersection.
    */
    std::vector<Point> result;

    // YOUR CODE HERE

    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> V(n);
    std::vector<int> V_coords(2 * n);
    for (int &item : V_coord) {
        std::cin >> item;
    }
    for (int i = 0; i < n; ++i) {
        V[i].x = V_coord[2 * i];
        V[i].y = V_coord[2 * i + 1];
    }
    int m;
    std::cin >> m;
    std::vector<Point> W(m);
    std::vector<int> W_coords(2 * m);
    for (int &item : W_coord) {
        std::cin >> item;
    }
    for (int i = 0; i < m; ++i) {
        W[i].x = V_coord[2 * i];
        W[i].y = V_coord[2 * i + 1];
    }
    std::vector<Point> res;
    res = determine_polygons_intersection(V, W);
    res_size = res.size();
    std::cout << res_size << std::endl;
    for (int i = 0; i < res_size; ++i) {
        std::cout << res[i].x << ' ' << res[i].y << ' ' << " ";
    }
}
