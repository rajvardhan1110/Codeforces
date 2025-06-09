#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> v[i][j];
            }
        }

        int cnt = 0;
        // int a = (n / 2);



        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int mirror_i = n - i - 1;
                int mirror_j = n - j - 1;
                if (i < mirror_i || (i == mirror_i && j < mirror_j)) {
                    if (v[i][j] != v[mirror_i][mirror_j]) {
                        cnt++;
                    }
                }

                
            }
        }

        if ((k >= cnt && (k - cnt) % 2 == 0) || (k >= cnt && n % 2 != 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}