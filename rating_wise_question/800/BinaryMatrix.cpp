#include <bits/stdc++.h>
using namespace std;
#define int long long

// Input a 1D vector
void inputV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

// Print a 1D vector
void printV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Sieve of Eratosthenes
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

// Check if number is power of two
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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

   
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j] - '0';
        }
    }

    vector<bool> row(n, true);
    vector<bool> col(m, true);

   
    for (int i = 0; i < n; i++) {
        int a = 0;
        for (int j = 0; j < m; j++) {
            a ^= v[i][j];
        }
        if (a == 1) row[i] = false;
    }

 
    for (int j = 0; j < m; j++) {
        int a = 0;
        for (int i = 0; i < n; i++) {
            a ^= v[i][j];
        }
        if (a == 1) col[j] = false;
    }

    
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (!row[i]) count1++;
    }
    for (int j = 0; j < m; j++) {
        if (!col[j]) count2++;
    }

    int ans = min(count1, count2);
    ans += max(count1, count2) - ans;

    cout << ans << endl;
}
