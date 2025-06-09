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

    ll n;
    cin>>n;


    string s;
    cin>>s;

    ll i =0;
    ll j = n-1;


    while(i <= j && (s[i]==s[j])){
        i++;
        j--;
    }

    if(i>j){
        cout<<0<<endl;
        return;
    }

    char A = s[i];
    char B = s[j];

    ll ans = 0;
    ll cnt1 = 0;
    ll cnt2 = 0;

    bool bool1 = false;
    bool bool2 = false;

    ll x = i;
    ll y = j;

    while(i<=j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else if(s[i] == A){
            cnt1++;
            i++;
        }else if(s[j] == A){
            cnt1++;
            j--;
        }else{
            bool1 = true;
            break;
        }
    }

    i = x;
    j = y;

    while(i<=j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else if(s[i] == B){
            cnt2++;
            i++;
        }else if(s[j] == B){
            cnt2++;
            j--;
        }else{
            bool2 = true;
            break;
        }
    }

    if(bool1 && bool2){
        cout<<-1<<endl;
    }else if(bool1 == false && bool2 ==false){
        cout<<min(cnt1,cnt2)<<endl;
    }else if(bool1 == false){
        cout<<cnt1<<endl;
    }else{
        cout<<cnt2<<endl;
    }
}