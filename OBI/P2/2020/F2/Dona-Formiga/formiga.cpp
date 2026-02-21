//accepted 40%
#include <iostream>
#include <vector>
#include <queue>

int BFS (std::vector<std::vector<int>> graph, int V, int start) {
    std::queue<int> q;
    int distances[V];
    for (int i = 0; i < V; ++i) distances[i] = 0;
    int src, cnt = 0;
    int srcDistance, neighborDistance;
    q.push(start);
    while (!q.empty()) {
        src = q.front();
        q.pop();
        srcDistance = distances[src];
        if (srcDistance > cnt) cnt = srcDistance;
        for (int neighbor : graph[src]) {
            q.push(neighbor);
            neighborDistance = distances[neighbor];
            if (neighborDistance < srcDistance+1) distances[neighbor] = srcDistance+1;
        }
    }
    return cnt;
}

int main() {
    int V, E, src;
    std::cin>>V>>E>>src;
    int heights[V], u, v;
    for (int i = 0; i < V; ++i) std::cin>>heights[i];
    std::vector<std::vector<int>> graph (V);
    for (int i = 0; i < E; ++i) {
        std::cin>>u>>v;
        --u; --v;
        if (heights[u] > heights[v]) {
            graph[u].push_back(v);
        } else {
            graph[v].push_back(u);
        }
    }
    std::cout<<BFS(graph, V, src-1)<<"\n";
    return 0;
}