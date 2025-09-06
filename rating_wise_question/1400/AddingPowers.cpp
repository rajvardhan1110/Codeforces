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

bool sumOfPowers(ll n, ll k, vector<ll> &powers) {
    ll powerIndex = 0; 
    while (n > 0) {
        ll digit = n % k;
        if (digit > 1) return false; 
        if (digit == 1) powers.push_back(powerIndex);
        n /= k;
        powerIndex++;
    }
    return true;
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

    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);
    inputV(arr,n);

    map<ll,ll> mp;

    for(ll i = 0; i<n; i++){
        

        if(arr[i] != 0){
            vector<ll> num;
           bool f = sumOfPowers(arr[i],k,num);
        //    printV(num);

            if(!f){
                cout<<"NO"<<endl;
                return;
            }else{
                for(ll i =0; i<num.size(); i++){
                    if(mp[num[i]] > 0){
                        cout<<"NO"<<endl;
                        return;
                    }else{
                        mp[num[i]]++;
                    }
                }
            }
        }
    }

    cout<<"YES"<<endl;
}