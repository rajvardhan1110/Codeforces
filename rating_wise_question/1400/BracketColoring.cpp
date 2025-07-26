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

    string s2 ="";

    for(auto i: s){
        if(i == '('){
            s2 += ')';
        }else{
            s2 += '(';
        }
    }

    stack<pair<char,ll>> st;
    stack<pair<char,ll>> st2;


    vector<ll> ans(n);

    ll c1 = 0;
    ll c2 = 0;

    for(ll i =0; i<n; i++){
        if(s[i] == '('){
            c1++;
        }else{
            c2++;
        }
    }

    if(c1 != c2){
        cout<<-1<<endl;
        return;
    }


    for(ll i = 0; i<n; i++){
        if(s[i] == ')'){
            if(!st.empty() && st.top().first == '('){
                ans[i] = 1;
                ans[st.top().second] = 1;

                st.pop();
            }else{
                st.push({s[i],i});
            }
        }else{
            st.push({s[i],i});
        }
    }

    // for(auto i:s2){
    //     cout<<i;
    // }

    for(ll i = 0; i<n; i++){
        if(s2[i] == ')'){
            if(!st2.empty() && st2.top().first == '('){
                ans[i] = 1;
                ans[st2.top().second] = 1;

                st2.pop();
            }else{
                st2.push({s2[i],i});
            }
        }else{
            st2.push({s2[i],i});
        }
    }


    if(st2.empty()){
        // cout<<"st2 is empty"<<endl;
        cout<<1<<endl;

        for(ll i = 0; i<n; i++){
            cout<<1<<" ";
        }

        cout<<endl;

        return;

    }
   



    if(!st.empty()){
        while(!st.empty()){
            ans[st.top().second] = 2;

                st.pop();
        }
    }else{
        cout<<1<<endl;
        for(ll i =0; i<n; i++){
            cout<<1<<"  ";
        }

        cout<<endl;
        return;
    }

    if(!st.empty()){
        cout<<-1<<endl;
        return;
    }

    ll cnt2 = 0;

    for(ll i =0; i<n; i++){
        if(ans[i] == 2){
            cnt2++;
        }
    }

    

    if(cnt2 == n){
       cout<<1<<endl;
        for(ll i =0; i<n; i++){
            cout<<1<<"  ";
        }

        cout<<endl;
        return;
    }else{
        cout<<2<<endl;
        for(ll i =0; i<n; i++){
            cout<<ans[i]<<" ";
        }

        cout<<endl;
        return;
    }
}