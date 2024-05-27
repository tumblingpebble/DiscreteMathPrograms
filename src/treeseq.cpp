#include <iostream>
#include <vector>

bool isTreeDegreeSequence(const std::vector<int>& degrees) {
    int sum = 0;
    for (int degree : degrees) {
        if (degree < 1) {
            // A tree must have no isolated vertices (degree 0)
            return false;
        }
        sum += degree;
    }
    // Sum of degrees should be twice the number of vertices minus 2
    return sum == 2 * (degrees.size() - 1);
}

int main() {
    int numVertices;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    std::vector<int> degrees(numVertices);
    std::cout << "Enter the degrees of each vertex: ";
    for (int i = 0; i < numVertices; ++i) {
        std::cin >> degrees[i];
    }

    if (isTreeDegreeSequence(degrees)) {
        std::cout << "The sequence can be the degree sequence of a tree." << std::endl;
    } else {
        std::cout << "The sequence cannot be the degree sequence of a tree." << std::endl;
    }

    return 0;
}
