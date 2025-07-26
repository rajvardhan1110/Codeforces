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

    if(n <= 2){
        ll num = stoll(s);
        cout<<num<<endl;
        return;
    }

    if(n == 3){
        if(s[0] == '0' || s[2] == '0'){
            
            cout<<0<<endl;
            return;
        }else if(s[1] == '0'){
            if(s[0]=='1' || s[2] == '1'){
                cout<<max(s[0]-'0',s[2]-'0')<<endl;
            }else{
                cout<<(s[0]-'0') + (s[2]-'0')<<endl;
            }
            return;
        }


    }

    ll mini = INT_MAX;

    if(s[s.size()-1] == '0'){
        cout<<0<<endl;
        return;
    }

    //cout<<s<<endl;

    

   ll ans = INT_MAX;

   ll sum = 0;
   for(auto i : s){

    if(i == '0'){
        cout<<0<<endl;
        return;
    }

    if(i != '1'){
        sum += (i-'0');
    }

   }

   for(ll i = 0; i<n-1; i++){
    ll newsum = sum;

    if(s[i] != '1'){
        newsum -= (s[i]-'0');
    }

    if(s[i+1] != '1'){
        newsum -= (s[i+1]-'0');
    }

    string addnum = s.substr(i,2);
    ll add = stoll(addnum);

    newsum += add;

    ans = min(ans,newsum);

   }

   cout<<ans<<endl;


}