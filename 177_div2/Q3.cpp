#include <bits/stdc++.h>
using namespace std;
#define int long long

void inputV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    vector<bool> c(n + 1, false);  

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) { 
        pos[a[i]] = i;
    }

    int cnt = 0; 

    for (int i = 1; i <= n; i++) {
        int num = b[i];

        if (!c[num]) { 
            int newcnt = 0;

            while (!c[num]) { 
                c[num] = true;
                newcnt++;
                num = pos[num];
            }

            cnt += newcnt;
        }

        cout << cnt << " ";
    }

    cout << endl;
}
