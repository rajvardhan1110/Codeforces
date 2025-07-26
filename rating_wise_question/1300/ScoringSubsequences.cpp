#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
        while (!pq.empty() && pq.top() < (int)pq.size()) {
            pq.pop();
        }
        cout << pq.size() << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
