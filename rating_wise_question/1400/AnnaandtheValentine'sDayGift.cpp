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

    ll n,m;
    cin>>n>>m;

    vector<ll> arr(n);
    inputV(arr,n);

    vector<ll> zero;
    ll no = 0;

    for(ll i= 0; i<n; i++){
        ll num = arr[i];
        int cnt = 0;

        while(num % 10 == 0){
            cnt++;
            num /= 10;
        }

        if(cnt > 0){
            zero.push_back(cnt);
        }else{
            no++;
        }
    }

    sort(zero.begin(),zero.end());
    ll del = 0;

    ll i = zero.size() - 1;

    while(i >= 0){

        del += zero[i];
        zero[i] = 0;

        if(zero[i] == 0){
            no++;
        }
        
        if(no > 0){
            if(i > 0){
                i -= 2;
            }else{
                i--;
            }
        }
        // else{
        //     if(i>0){
        //         zero[i-1] = min(zero[i],zero[i-1]); 
        //         i--;
        //     }else{
        //         i--;
        //     }
        // }
        
    }

    ll totaldigits = 0;

    for(ll i= 0; i<n; i++){
        ll num = arr[i];
        int cnt = 0;

        while(num > 0){
            cnt++;
            num /= 10;
        }

       totaldigits += cnt;
    }

    totaldigits -= del;

    if(totaldigits >= m+1){
        cout<<"Sasha"<<endl;
    }else{
        cout<<"Anna"<<endl;
    }

}