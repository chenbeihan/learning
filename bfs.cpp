// Example program
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

// ---------- Graph demo ----------
// 1. Undirected graph, unit edge weight
// 2. Adjacency-list representation
// 3. BFS for single-source shortest distances
// ---------------------------------

int main() {
    // 1. Read number of vertices (n) and edges (m)
    int n, m;
    //cout << "Enter number of vertices (n) and edges (m): ";
    if (!(cin >> n >> m)) return 0;

    // 2. Build adjacency list
    vector<vector<int>> adj(n + 1);          // vertices numbered 1..n
    //cout << "Next, enter " << m << " undirected edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u); //注释掉即为有向边（单行道），没注释掉就是无向边（双行道）
    }
    
    cout << "\nAdjacency list:\n";
    for (int u = 1; u <= n; ++u) {
        cout << "Vertex " << u << ":";
        for (int v : adj[u]) cout << ' ' << v;
        cout << '\n';
    }

    // 3. BFS to compute shortest distances
    int start;
    cout << "Enter the source vertex: ";
    cin >> start;

    vector<int> dist(n + 1, -1);             // -1 means unvisited
    queue<int> q;

    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {             // not visited yet
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // 4. Output results
    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int u = 1; u <= n; ++u) {
        cout << "To vertex " << u << ": "
             << (dist[u] == -1 ? "unreachable" : to_string(dist[u])) << endl;
    }
    cout << "\nPress ENTER to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清掉之前残留的换行
    cin.get();                                           // 等待回车
    return 0;
}
