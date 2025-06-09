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
    cout << "\n";
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
    return 0;
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<int> v(n);
    inputV(v, n);

    int a = accumulate(v.begin(), v.end(), 0LL);
    
    int maxAns = a * k;
    if (x > maxAns) {
        cout << 0 << "\n";
        return;
    }
    
    int basic = a;
    int maxCount = n * k;
    int cnt = 0;
    int gr = x / basic;
    int grcnt = gr * n;
    int req = x % basic;
    
    if (req == 0) {
        cout << maxCount - grcnt + 1 << "\n";
        return;
    }
    
    int curr = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (curr + v[i] < req) {
            curr += v[i];
            cnt++;
        } else {
            break;
        }
    }
    
    cout << maxCount - (cnt + grcnt) << "\n";
}
