#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::string determine_point_position(int A_x, int A_y, int B_x, int B_y, int C_x, int C_y, int p_x, int p_y) {
    /*
    Given a triangle ABC and n points p1, p2, ... , pn on the plane, determine for each point
    whether it is inside, outside, or on the border of the triangle.
    A_x, A_y, B_x, B_y, C_x, C_y are coordinates of A, B and C respectively.
    p_x, p_y - coordinates of p.
    return: one of {"INSIDE", "OUTSIDE", "BORDER"}
    */
    std::string result;

    // YOUR CODE HERE

    return result;
}

int main() {
    int A_x, A_y, B_x, B_y, C_x, C_y;
    std::cin >> A_x >> A_y >> B_x >> B_y >> C_x >> C_y;
    int n;
    std::cin >> n;
    std::vector<int> p_x(n);
    std::vector<int> p_y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p_x[i] >> p_y[i];
    }
    for (int i = 0; i < n; ++i) {
        std::string result;
        result = determine_point_position(A_x, A_y, B_x, B_y, C_x, C_y, p_x[i], p_y[i]);
        std::cout << result << std::endl;
    }
}
