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
        cout << v[i];
    }
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
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    int r, c, k;
    cin >> r >> c >> k;

    

    bool flag = true;
    int count = 0;

    if (c % k == 0) {
        for (int i = 0; i < r; i++) {
            if (flag) {
                cout<<1<<" ";
                int cnt=1;
                for (int j = 1; j < c; j++) {
                    cout << (cnt%k) + 1 << " ";
                    cnt++;
                }
                flag = false;
            } else {

                cout<<k<<" ";
                int cnt=0;
                for (int j = 1; j < c; j++) {
                    cout <<(cnt%k) + 1<< " ";
                    cnt++;
                }
                flag = true;
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << (count % k) + 1 << " ";
                count++;
            }
            cout << endl;
        }
    }
}
