#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
int deg[N], leaves[N], subtree_size[N];
int n;

// DFS to count leaves in each subtree
void dfs_leaves(int u, int parent) {
    if (deg[u] == 1) { // leaf
        leaves[u] = 1;
    }
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs_leaves(v, u);
        leaves[u] += leaves[v];
    }
}

// DFS to count size of each subtree
void dfs_size(int u, int parent) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs_size(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        // reset
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            deg[i] = leaves[i] = subtree_size[i] = 0;
        }

        // input tree
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        // check star case
        bool is_star = false;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == n - 1) {
                is_star = true;
                break;
            }
        }
        if (is_star) {
            cout << 0 << "\n";
            continue;
        }

        // run DFS
        dfs_leaves(1, 0);
        dfs_size(1, 0);

        int total_leaves = leaves[1];
        int ans = INT_MAX;

        // try each node as center
        for (int i = 1; i <= n; i++) {
            int ops = 0;

            // leaves inside each child subtree
            for (int v : adj[i]) {
                if (subtree_size[v] < subtree_size[i]) {
                    if (subtree_size[v] > 1) {
                        ops += leaves[v];
                    }
                }
            }

            // leaves outside the subtree
            if (i != 1) {
                int outside = total_leaves - leaves[i];
                if (n - subtree_size[i] > 1) {
                    ops += outside;
                }
            }

            ans = min(ans, ops);
        }

        cout << ans << "\n";
    }
}
