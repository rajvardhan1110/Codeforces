#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> numToNum;
    map<int, int> first, sec;

    int count = 0;

    for (int i = 0; i < n; i++) {
        numToNum[a[i]] = b[i];
        first[a[i]] = i + 1;
        sec[b[i]] = i + 1;
    }

    for (auto i : numToNum) {
        if (i.first == i.second) {
            count++;
        } else {
            if (numToNum[i.second] != i.first) {
                cout << -1 << endl;
                return;
            }
        }
    }

    if (n % 2 != 0) {
        if (count >= 2 || count != 1) {
            cout << -1 << endl;
            return;
        }
    } else {
        if (count >= 1) {
            cout << -1 << endl;
            return;
        }
    }

    vector<pair<int, int>> v;

    if (n % 2 != 0) {
        int cnt = 0;
        int x = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                cnt++;
                x = i;
            }
        }

        if (cnt == 1) {
            swap(a[x], a[n / 2]);
            swap(b[x], b[n / 2]);
            v.push_back({x, n / 2});
        } else {
            cout << -1 << endl;
            return;
        }
    }

    map<int, int> mp1, mp2;

    for (int i = 0; i < n; i++) {
        mp1[a[i]] = i;
        mp2[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (n - mp1[a[i]] - 1 != mp2[a[i]]) {
            int x = n - mp1[a[i]] - 1;
            int y = mp2[a[i]];

            mp1[a[x]] = y;
            mp1[a[y]] = x;

            mp2[b[x]] = y;
            mp2[b[y]] = x;

            swap(a[x], a[y]);
            swap(b[x], b[y]);

            v.push_back({x, y});
        }
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[n - 1 - i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << v.size() << "\n";
        for (auto it : v) {
            cout << it.first + 1 << " " << it.second + 1 << "\n";
        }
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
