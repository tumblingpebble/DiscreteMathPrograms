#include <iostream>
#include <vector>
#include <queue>

// Function to check if a graph is bipartite using BFS
bool isBipartite(const std::vector<std::vector<int>>& graph, int start, std::vector<int>& colors) {
    std::queue<int> q;
    q.push(start);
    colors[start] = 1; // Color the start vertex with color 1

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (colors[neighbor] == -1) {
                // If the neighbor has not been colored, color it with the opposite color
                colors[neighbor] = 1 - colors[current];
                q.push(neighbor);
            } else if (colors[neighbor] == colors[current]) {
                // If the neighbor has the same color as the current vertex, the graph is not bipartite
                return false;
            }
        }
    }

    return true;
}

int main() {
    int V; // Number of vertices
    int E; // Number of edges
    std::cout << "Enter number of vertices and edges: ";
    std::cin >> V >> E;

    std::vector<std::vector<int>> graph(V);
    std::vector<int> colors(V, -1); // Color array to store colors of vertices, initialized with -1

    // Reading edges of the graph
    std::cout << "Enter the edges (u v) for the graph:" << std::endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }

    // Check if the graph is bipartite starting from each vertex (in case the graph is disconnected)
    bool result = true;
    for (int i = 0; i < V; ++i) {
        if (colors[i] == -1) {
            if (!isBipartite(graph, i, colors)) {
                result = false;
                break;
            }
        }
    }

    if (result) {
        std::cout << "The graph is bipartite." << std::endl;
    } else {
        std::cout << "The graph is not bipartite." << std::endl;
    }

    return 0;
}
