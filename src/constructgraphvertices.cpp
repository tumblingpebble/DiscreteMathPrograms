#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Graph {
private:
    std::map<std::string, int> vertices; // Stores vertices and their degrees
    std::vector<std::pair<std::string, std::string>> edges; // Stores the edges

public:
    // Add a vertex with a given degree
    void addVertex(const std::string& vertex, int degree) {
        vertices[vertex] = degree;
    }

    // Construct the graph based on the specific strategy
void constructGraph() {
    while (!vertices.empty()) {
        // Sort vertices by degree in descending order
        std::vector<std::pair<std::string, int>> sortedVertices(vertices.begin(), vertices.end());
        std::sort(sortedVertices.begin(), sortedVertices.end(),
                  [](const auto& a, const auto& b) { return a.second > b.second; });

        // Get vertex with highest degree
        auto& maxVertex = sortedVertices.front();

        if (maxVertex.second == 0) {
            break; // All degrees are zero, stop the construction
        }

        // Connect this vertex to others
        for (int i = 1; i < sortedVertices.size() && maxVertex.second > 0; ++i) {
            auto& connectTo = sortedVertices[i];

            // Check if the edge already exists and if connectTo vertex has a non-zero degree
            if (connectTo.second > 0 && !edgeExists(maxVertex.first, connectTo.first)) {
                // Create edge
                edges.emplace_back(maxVertex.first, connectTo.first);

                // Decrease degrees
                maxVertex.second--;
                connectTo.second--;

                // Update the original map
                vertices[maxVertex.first] = maxVertex.second;
                vertices[connectTo.first] = connectTo.second;
            }
        }

        // Remove vertex if its degree is zero
        if (maxVertex.second == 0) {
            vertices.erase(maxVertex.first);
        }
    }
}

// Helper function to check if an edge already exists
bool edgeExists(const std::string& vertex1, const std::string& vertex2) {
    return std::find_if(edges.begin(), edges.end(), [&](const auto& edge) {
        return (edge.first == vertex1 && edge.second == vertex2) ||
               (edge.first == vertex2 && edge.second == vertex1);
    }) != edges.end();
}



    // Print the edges of the graph
    void printEdges() {
        for (const auto& edge : edges) {
            std::cout << edge.first << "-" << edge.second << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Graph g;
    int numVertices, degree;
    std::string vertex;

    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Enter vertex name: ";
        std::cin >> vertex;
        std::cout << "Enter degree for vertex " << vertex << ": ";
        std::cin >> degree;
        g.addVertex(vertex, degree);
    }

    // Construct the graph
    g.constructGraph();

    // Print the edges of the graph
    g.printEdges();

    return 0;
}
