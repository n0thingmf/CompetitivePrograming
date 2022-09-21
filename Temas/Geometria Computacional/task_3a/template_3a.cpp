#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::string determine_relative_position(int A_x, int A_y, int B_x, int B_y, int C_x, int C_y, int D_x, int D_y) {
    /*
    Determine relative position of segments AB and CD.
    8 args of this function are coordinates of A, B, C, D
    Return one message of one of the following formats:
    No common points.
    The intersection point is (E_x, E_y).
    A common segment of non-zero length.
    */
    std::string result;

    // YOUR CODE HERE

    return result;
}

int main() {
    int A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y;
    std::cin >> A_x >> A_y >> B_x >> B_y;
    std::cin >> C_x >> C_y >> D_x >> D_y;
    result = determine_relative_position(A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y);
    std::cout << result << std::endl;
}
