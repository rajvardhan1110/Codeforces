#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void inputV(vector<ll>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
}

bool canMatchAfterInsert(const vector<ll>& a, const vector<ll>& b, ll k) {
    int n = a.size(), m = b.size();
    for (int insertPos = 0; insertPos <= n; ++insertPos) {
        int i = 0, j = 0;
        bool used = false;

        while (j < m) {
            if (i == insertPos && !used) {
               
                if (k >= b[j]) {
                    j++;
                }
                used = true;
                continue;
            }

            if (i >= n) break;

            if (a[i] >= b[j]) {
                i++; j++;
            } else {
                i++;
            }
        }

        if (j == m) return true;
    }
    return false;
}


bool canMatchWithoutInsert(const vector<ll>& a, const vector<ll>& b) {
    ll i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] >= b[j]) {
            j++;
        }
        i++;
    }
    return j == b.size();
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a, b;
    inputV(a, n);
    inputV(b, m);

    if (canMatchWithoutInsert(a, b)) {
        cout << 0 << '\n';
        return;
    }

    ll lo = 1, hi = 1e9, ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (canMatchAfterInsert(a, b, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // Safety limit: Cap total elements read to avoid abuse
    ll totalN = 0;
    while (t--) {
        solve();
    }

    return 0;
}
