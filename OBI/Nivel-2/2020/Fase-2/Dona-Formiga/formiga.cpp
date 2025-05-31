#include <iostream>
#include <vector>

void DFS (std::vector<std::vector<int>> graph, int heights[], bool visited[], int src, int& cnt) {
    visited[src] = true;
    ++cnt;
    for (int neighbor : graph[src]) {
        if (!visited[neighbor] && heights[src] > heights[neighbor]) DFS(graph, heights, visited, neighbor, cnt);
    }
}

int main() {
    int V, E, src, connected = -1;
    std::cin>>V>>E>>src;
    int heights[V], u, v;
    bool visited[V];
    for (int i = 0; i < V; ++i) {
        std::cin>>heights[i];
        visited[i] = false;
    }
    std::vector<std::vector<int>> graph (V);
    for (int i = 0; i < E; ++i) {
        std::cin>>u>>v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS (graph, heights, visited, src-1, connected);
    std::cout<<connected<<"\n";
    return 0;
}