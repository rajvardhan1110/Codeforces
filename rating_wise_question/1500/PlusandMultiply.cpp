#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve2(ll num, ll a, ll b, ll n) {
    if (num > n) return false;               
    if ((n - num) % b == 0) return true;     

    if (a == 1) return false;                

    return solve2(num * a, a, b, n);        
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (solve2(1, a, b, n)) cout << "Yes"<<endl;
    else cout << "No"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
