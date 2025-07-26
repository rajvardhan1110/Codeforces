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

ll countTrailingZeros(ll x) {
    ll cnt = 0;
    while (x % 10 == 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
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

    ll n, m;
    cin >> n >> m;

        // ll bestK = 1;
        // int bestZeros = countTrailingZeros(n);
        // ll result = n;

        
        // ll curK = 1;

        
        // for (ll x = 1; x <= m; x *= 2) {
        //     for (ll y = 1; x * y <= m; y *= 5) {
        //         ll k = x * y;
        //         ll maxMult = m / k;
        //         ll finalK = k * maxMult;
        //         ll product = n * finalK;
        //         int zeros = countTrailingZeros(product);
        //         if (zeros > bestZeros || (zeros == bestZeros && product > result)) {
        //             bestZeros = zeros;
        //             result = product;
        //         }
        //     }
        // }

        // cout << result << '\n';

    ll two = 0;
    ll five = 0;

    ll num = n;

    while(n>1 && n % 2 == 0){
        two++;
        n /= 2;
    }

    while(n>1 && n % 5 == 0){
        five++;
        n /= 5;
    }

    ll multi = 1;

    if(two > five){
        for(ll i =0; i<two-five; i++){
            if(multi * 5 <= m){
                multi *= 5;
            }
        }
    }else{
        for(ll i =0; i<five-two; i++){
            if(multi * 2 <= m){
                multi *= 2;
            }
        }
    }

    while(multi*10 <= m){
        multi *= 10;
    }

    cout<<(m/multi)*multi*num<<endl;
    
}