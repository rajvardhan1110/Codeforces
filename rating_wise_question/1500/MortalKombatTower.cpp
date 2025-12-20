#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> bosses;        // 0 = easy, 1 = hard
vector<vector<int>> dp;    // memoization table

// Recursive function:
// i = current boss index (1-based)
// turn = 1 if friend's turn, 0 if our turn
int minSkip(int i, int turn) {
    if (i > n) return 0;   // all bosses done

    if (dp[i][turn] != -1) return dp[i][turn];

    int ans = INT_MAX;

    // Option 1: kill 1 boss
    int skip = (turn == 1 && bosses[i] == 1) ? 1 : 0;
    ans = min(ans, skip + minSkip(i + 1, 1 - turn));

    // Option 2: kill 2 bosses (if possible)
    if (i + 1 <= n) {
        skip = 0;
        if (turn == 1) skip = bosses[i] + bosses[i + 1]; // count hard bosses
        ans = min(ans, skip + minSkip(i + 2, 1 - turn));
    }

    return dp[i][turn] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        bosses.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> bosses[i];

        dp.assign(n + 2, vector<int>(2, -1));

        cout << minSkip(1, 1) << "\n";  // friend starts
    }

    return 0;
}
