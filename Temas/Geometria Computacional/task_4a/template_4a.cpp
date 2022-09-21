#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Point {
public:
    int x;
    int y;
};

std::string determine_AB_location(const std::vector<Point>& V, int a, int b) {
    /*
    Given a simple polygon and its diagonal,
    check, whether it is external, internal, or intersects the side.
    V is an array of vertices of a polygon, a and b are indices of considered vertices.
    Return one of the following messages: {"INTERSECT, "INTERNAL", "EXTERNAL"}.
    */

    // YOUR CODE HERE

}

int main() {
    int n;
    std::cin >> n;
    int m;
    std::vector<Point> V(n);
    std::vector<int> V_coord(2 * n);
    for (int &item : V_coord) {
        std::cin >> item;
    }
    for (int i = 0; i < n; ++i) {
        V[i].x = V_coord[2 * i];
        V[i].y = V_coord[2 * i + 1];
    }
    int number_of_diags;

    // YOUR CODE HERE

    std::cout << number_of_diags << std::endl;
    for (int i = 0; i < V.size(); ++i) {
        for (int j = i + 2; j < V.size(); ++j) {

            // YOUR CODE HERE

            std::string result;
            result = determine_AB_location(V, V[i], V[j], i);
            std::cout << V[i].x << ' ' << V[i].y << ' ' << V[j].x << ' ' << V[j].y << ' ' << result << std::endl;
        }
    }
}
