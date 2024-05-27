#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void combine(std::vector<std::vector<int>>& all_combinations, std::vector<int>& combination, int n, int r, int index, int i) {
    if (index == r) {
        all_combinations.push_back(combination);
        return;
    }

    if (i >= n) return;

    combination[index] = i;
    combine(all_combinations, combination, n, r, index + 1, i + 1); // Include the current element
    combine(all_combinations, combination, n, r, index, i + 1); // Move to the next element
}

// Utility function to check for a K_1,4 subgraph
bool isK14(const std::vector<std::vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[i].size() >= 4) { // Check if the vertex is connected to at least 4 other vertices
            std::cout << "K_1,4 subgraph detected with central vertex: " << i << std::endl;
            // Optionally print the connected vertices (leaves)
            return true;
        }
    }
    return false;
}

// Utility function to check if two vertices have an edge between them
bool hasEdge(const std::vector<std::vector<int>>& graph, int u, int v) {
    return std::find(graph[u].begin(), graph[u].end(), v) != graph[u].end();
}

// Utility function to check for a C_4 subgraph
bool isC4(const std::vector<std::vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = i + 1; j < graph.size(); ++j) {
            if (hasEdge(graph, i, j)) {
                for (int k = j + 1; k < graph.size(); ++k) {
                    if (hasEdge(graph, j, k) && hasEdge(graph, i, k)) {
                        for (int l = k + 1; l < graph.size(); ++l) {
                            if (hasEdge(graph, k, l) && hasEdge(graph, i, l)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

// Utility function to check if a given subgraph is complete
bool isComplete(const std::vector<std::vector<int>>& graph, const std::vector<int>& subgraph) {
    for (int i = 0; i < subgraph.size(); ++i) {
        for (int j = i + 1; j < subgraph.size(); ++j) {
            if (std::find(graph[subgraph[i]].begin(), graph[subgraph[i]].end(), subgraph[j]) == graph[subgraph[i]].end()) {
                return false;
            }
        }
    }
    return true;
}

// Utility function to check if a given subgraph forms a path of length n
bool isPath(const std::vector<std::vector<int>>& graph, int n, int start) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<std::pair<int, int>> q; // Pair of vertex and length of path so far

    visited[start] = true;
    q.push({start, 0});

    while (!q.empty()) {
        auto [current, length] = q.front();
        q.pop();

        if (length == n) return true;

        for (int adj : graph[current]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push({adj, length + 1});
            }
        }
    }

    return false;
}


// Main program to detect subgraphs
int main() {
    int V, E;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> V >> E;

    std::vector<std::vector<int>> graph(V);
    std::vector<char> vertices(V);
    std::cout << "Enter the vertices (single character each): ";
    for (int i = 0; i < V; ++i) {
        std::cin >> vertices[i];
    }

    std::cout << "Enter the edges in the format 'a b':\n";
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < E; ++i) {
        char u, v;
        std::cin >> u >> v;
        int u_index = std::find(vertices.begin(), vertices.end(), u) - vertices.begin();
        int v_index = std::find(vertices.begin(), vertices.end(), v) - vertices.begin();
        if (u_index != v_index && std::find(edges.begin(), edges.end(), std::make_pair(u_index, v_index)) == edges.end()) {
            graph[u_index].push_back(v_index);
            graph[v_index].push_back(u_index); // Assuming the graph is undirected
            edges.emplace_back(u_index, v_index);
        }
    }
    // Check for complete graph K_5
    if (V >= 5) {
    std::vector<int> k5;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            for (int k = j + 1; k < V; ++k) {
                for (int l = k + 1; l < V; ++l) {
                    for (int m = l + 1; m < V; ++m) {
                        k5 = {i, j, k, l, m};
                        if (isComplete(graph, k5)) {
                            std::cout << "Complete graph K_5 detected with vertices: ";
                            for (int vertex : k5) {
                                std::cout << vertices[vertex] << ' ';
                            }
                            std::cout << '\n';
                        }
                    }
                }
            }
        }
    }
    }
// Check for path P_2 (which is simply an edge)
for (int i = 0; i < V; ++i) {
    for (int j : graph[i]) {
        if (i < j) { // To avoid counting an edge twice
            std::cout << "Path P_2 detected with vertices: " << vertices[i] << ' ' << vertices[j] << '\n';
        }
    }
}
//check for complete graph k_6
std::vector<std::vector<int>> all_combinations;
std::vector<int> combination(6);
combine(all_combinations, combination, V, 6, 0, 0);
    for (const auto& comb : all_combinations) {
        if (isComplete(graph, comb)) {
            std::cout << "Complete graph K_6 detected with vertices: ";
            for (int vertex : comb) {
                std::cout << vertices[vertex] << ' ';
            }
            std::cout << '\n';
            break; // Assuming we only want to detect one instance
        }
    }

// Check for K_1,4
// Check for K_1,4
for (int i = 0; i < V; ++i) {
    if (graph[i].size() >= 4) { // Check if the vertex is connected to at least 4 other vertices
        std::cout << "K_1,4 subgraph detected centered at vertex: " << vertices[i] << std::endl;
        // Optionally print the connected vertices (leaves)
    }
}

    // Check for C_4
    if (V >= 4) {
    if (isC4(graph)) {
        std::cout << "The graph contains a C_4 subgraph." << std::endl;
    }
    // Check for P_5 (using isPath with n = 5)
if (V >= 6) {
    for (int start = 0; start < V; ++start) {
        if (isPath(graph, 5, start)) { // This should be changed to check for a path with 5 edges
            std::cout << "Path P_5 detected starting at vertex: " << vertices[start] << '\n';
            break; // Assuming we only want to detect one instance
        }
    }
}

    // To check for the other subgraphs (K_3,3, K_6, P_5, K_1,4, C_4), you would need to implement
    // additional functions similar to isComplete and isPath that follow the definitions of those subgraphs.
    }
    return 0;
}