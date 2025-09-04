// 原代码 → 改成 DFS（显式栈版）
#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* 1. 读入 n、m */
    int n, m;
    if (!(cin >> n >> m)) return 0;

    /* 2. 建无向邻接表（同原代码） */
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /* 3. 选择起点 */
    int start;
    cout << "Enter the source vertex: ";
    cin >> start;

    /* 4. DFS 用栈，dist 初始 -1 */
    vector<int> dist(n + 1, -1);
    stack<int> st;
    dist[start] = 0;
    st.push(start);

    /* 5. 显式 DFS */
    while (!st.empty()) {
        int u = st.top();   // 只看栈顶，不急着 pop（可 pop 也可不 pop）
        st.pop();           // 弹出当前节点

        for (int v : adj[u]) {
            if (dist[v] == -1) {   // 未访问
                dist[v] = dist[u] + 1;
                st.push(v);        // 深度优先：立即把 v 压栈
            }
        }
    }

    /* 6. 输出结果（同原代码） */
    cout << "\nDFS shortest distances from vertex " << start << ":\n";
    for (int u = 1; u <= n; ++u)
        cout << "To vertex " << u << ": "
             << (dist[u] == -1 ? "unreachable" : to_string(dist[u])) << '\n';

    cout << "\nPress ENTER to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}
