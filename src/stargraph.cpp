#include <iostream>

int main() {
    int n;
    std::cout << "Enter the number of vertices in the star graph (S_n, including the central vertex): ";
    std::cin >> n;
    std::cout << "Number of edges in S_" << n << " is " << n << std::endl;
    return 0;
}
