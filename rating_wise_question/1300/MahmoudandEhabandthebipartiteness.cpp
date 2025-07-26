#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1); 
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> level(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;

   
    q.push(1);
    visited[1] = true;
    level[1] = 1; 

    long long odd_nodes = 0, even_nodes = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (level[u] % 2 == 1) odd_nodes++;
        else even_nodes++;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    cout << (odd_nodes * even_nodes) - (n - 1) << "\n";
    return 0;
}