#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Point {
public:
    int x;
    int y;
};

std::vector<std::vector<Point>> list_all_triangles(const std::vector<Point>& polygon) {
    /*
    Triangulate a~given polygon by the ear-cutting algorithm.
    Polygon is given as an array of its vertices.
    Return an array of triples (A, B, C) for every triangle ABC.
    */
    std::vector<std::vector<Point>> list_of_triangles;

    // YOUR CODE HERE

    return list_of_triangles;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> V(n);
    std::vector<int> V_coord(2 * n);
    for (int &item : V_coord) {
        std::cin >> item;
    }
    for (int i = 0; i < n; ++i) {
        V[i].x = V_coord[2 * i];
        V[i].y = V_coord[2 * i + 1];
    }
    std::vector<std::vector<Point>> triangulation;
    triangulation = list_all_triangles(V);
    int number_of_triags;
    number_of_triags = triangulation.size();
    std::cout << number_of_triags << std::endl;
    for (int i = 0; i < number_of_triags; ++i) {
        std::cout << triangulation[i][0].x << ' ' << triangulation[i][0].y << ' ' << triangulation[i][1].x << ' ' << triangulation[i][1].y << ' ' << triangulation[i][2].x << ' ' << triangulation[i][2].y << std::endl;
    }
}
