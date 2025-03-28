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

    int n,k;
    cin >> n >> k;


    vector <int> arr(n);
    inputV(arr,n);

    if (n == k) {

        int count = 1;

        for (int i = 1; i < n; i += 2) {
            if (arr[i] != count) {
                cout << count << endl;
                return;
            }
            count++;
        }   
        cout << count << endl;
        return;
    }

    int p = n - k + 1;

    if (arr[0] != 1) {
        for (int i = 1; i <= p; i++) {
        if (arr[i] != 1) {
            cout << 1 << endl;
            return;
        }
        }

    }
    else {

        for (int i = 0; i <= p; i++) {
        if (arr[i] != 1) {
            cout << 1 << endl;
            return;
        }
    }

    }

    
    cout << 2 << endl;

    
}