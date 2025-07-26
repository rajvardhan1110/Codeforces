#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sum_first_m(ll m) {
    return m * (m + 1) / 2;
}

ll sum_second_m(ll m, ll n) {
    return m * (2 * n - 1 - m) / 2;
}

void solve() {
    ll n, x;
    cin >> n >> x;

    ll total_first_half = n * (n + 1) / 2;
    ll total_second_half = n * (n - 1) / 2;
    ll total = total_first_half + total_second_half;

    if (x >= total) {
        cout << 2 * n - 1 << "\n";
        return;
    }

    if (x <= total_first_half) {
        ll left = 1, right = n;
        ll ans = n;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (sum_first_m(mid) >= x) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    } else {
        ll remaining_x = x - total_first_half;
        ll left = 1, right = n - 1;
        ll ans = n;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (sum_second_m(mid, n) >= remaining_x) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << n + ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}