#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else {
        return (res * res) % MOD;
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    string s;
    cin >> s;

    if (s[0] == 'R' && s.find('C') != string::npos && isdigit(s[1])) {

        int posC = s.find('C');
        ll row = stoll(s.substr(1, posC - 1));
        ll col = stoll(s.substr(posC + 1));

        
        string result = "";
        while (col > 0) {
            col--; 
            result += char('A' + (col % 26));
            col /= 26;
        }
        reverse(result.begin(), result.end());

        cout << result << row << endl;
    }
    else {
        string col = "";
        string row = "";

        for (char c : s) {
            if (isalpha(c)) col += c;
            else row += c;
        }

        ll colNum = 0;
        for (char c : col) {
            colNum = colNum * 26 + (c - 'A' + 1);
        }

        cout << "R" << row << "C" << colNum << endl;
    }
}