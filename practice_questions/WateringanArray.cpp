#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        long long d;
        cin >> n >> k >> d;

        vector<int> a(n), v(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> v[i];

        vector<int> cnt(n, 0);
        int ans = 0;

        int limit = min((long long)n, d);

        for (int day = 0; day <= limit; day++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] + cnt[j] == j + 1) {
                    cur++;
                }
            }

            long long rem = d - day;
            int total = cur + rem / 2;

            ans = max(ans, total);

            if (day == limit) break;

            int b = v[day % k];
            for (int j = 0; j < b; j++) {
                cnt[j]++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}