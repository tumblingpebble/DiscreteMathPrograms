#include <iostream>

int main() {
    int m, n;
    std::cout << "Enter the number of vertices in the first set (m) and second set (n) for the complete bipartite graph (K_{m,n}): ";
    std::cin >> m >> n;
    std::cout << "Number of edges in K_{" << m << "," << n << "} is " << (m * n) << std::endl;
    return 0;
}
