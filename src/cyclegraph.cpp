#include <iostream>

int main() {
    int n;
    std::cout << "Enter the number of vertices in the cycle graph (C_n): ";
    std::cin >> n;
    std::cout << "Number of edges in C_" << n << " is " << n << std::endl;
    return 0;
}
