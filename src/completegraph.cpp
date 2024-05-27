#include <iostream>

int main() {
    int n;
    std::cout << "Enter the number of vertices in the complete graph (K_n): ";
    std::cin >> n;
    std::cout << "Number of edges in K_" << n << " is " << (n * (n - 1) / 2) << std::endl;
    return 0;
}
