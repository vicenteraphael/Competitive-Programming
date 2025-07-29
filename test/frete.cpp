//probably accepted
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

int dijkstra (Graph graph, int n) {
    int dist[n], mark[n];
    for (int i=0;i<n;++i) {
        dist[i] = 1001;
        mark[i] = 0;
    }
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    int u, v, w;
    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();
        if (mark[u]) continue;
        mark[u] = 1;
        for (auto V : graph[u]) {
            v = V.first; w = V.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[n-1];
}

int main() {
    int V, E, u, v, w;
    scanf ("%d %d", &V, &E);
    Graph graph(V);
    while (E--) {
        scanf ("%d %d %d", &u, &v, &w);
        --u;--v;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    printf ("%d\n", dijkstra(graph, V));
    return 0;
}
