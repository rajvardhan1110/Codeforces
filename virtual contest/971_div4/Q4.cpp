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
        ll x,y,k;
        cin>>x>>y>>k;

        ll maxi = max(x,y);

        // if(maxi % k == 0){
        //     cout<<(maxi/k * 2) - 1<<endl;
        // }else{
        //     cout<<((maxi/k)+1)*2<<endl;
        // }

        // if(x > y){

        //     if(x % k == 0){
        //         cout<<(x/k) *2 - 1<<endl;
        //     }else{
        //         cout<<(x/k + 1) *2 - 1<<endl;
        //     }
            
        // }else{

        //     if(y%k == 0){
        //         cout<<((y/k)) * 2<<endl;
        //     }else{
        //         cout<<((y/k)+1) * 2<<endl;
        //     }
            
        // }



        ll a = 0;
        if(x % k == 0){
            a = x/k;
        }else{
            a = x/k + 1;
        }

        ll b = 0;
        if(y % k == 0){
            b = y/k;
        }else{
            b = y/k + 1;
        }

        if(a > b){
            cout<<a*2 - 1<<endl;
        }else{
            cout<<b*2<<endl;
        }
    }