#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq; 
    ll health = 0;

    for (int i = 0; i < n; i++) {
        health += a[i];
        pq.push(a[i]);

        while (!pq.empty() && health < 0) {
           
            health -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << endl;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
