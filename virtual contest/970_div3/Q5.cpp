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


    map<char,ll> even;
    map<char,ll> odd;

    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            even[s[i]]++;
        }else{
            odd[s[i]]++;
        }
    }

    if(n%2 == 0){

        ll maxie = 0;
        ll maxio = 0;

        for(auto i : even){
            maxie = max(maxie,i.second);
        }

        for(auto i : odd){
            maxio = max(maxio,i.second);
        }

        cout<<n-(maxie+maxio)<<endl;



    }else{

        map<char,ll> curreven;
        map<char,ll> currodd;

        ll mini = INT_MAX;


        for(ll i =0; i<n; i++){
            if(i % 2 == 0){
                ll num = even[s[i]];
                even[s[i]]--;

                map<char,ll> neweven;
                map<char,ll> newodd;
.
                for(auto i : even){
                    newodd[i.first] += currodd[i.first] + (even[i.first] - curreven[i.first]);
                }

                for(auto i:currodd){
                    if(newodd[i.first] == 0){
                        newodd[i.first] = currodd[i.first];
                    }
                }

                for(auto i : odd){
                    neweven[i.first] += curreven[i.first] + (odd[i.first] - currodd[i.first]);
                }

                for(auto i:curreven){
                    if(neweven[i.first] == 0){
                        neweven[i.first] = curreven[i.first];
                    }
                }

                ll maxie = 0;
                ll maxio = 0;



                for(auto i : neweven){
                    maxie = max(maxie,i.second);
                }

                for(auto i : newodd){
                    maxio = max(maxio,i.second);
                }

                ll si = n-1;

                mini = min(mini,n-(maxie+maxio));

                even[s[i]]++;

                curreven[s[i]]++;

            }else{
                ll num = odd[s[i]];
                odd[s[i]]--;

                map<char,ll> neweven;
                map<char,ll> newodd;

                for(auto i : even){
                    newodd[i.first] += currodd[i.first] + (even[i.first] - curreven[i.first]);
                }

                for(auto i:currodd){
                    if(newodd[i.first] == 0){
                        newodd[i.first] = currodd[i.first];
                    }
                }

                for(auto i : odd){
                    neweven[i.first] += curreven[i.first] + (odd[i.first] - currodd[i.first]);
                }

                for(auto i:curreven){
                    if(neweven[i.first] == 0){
                        neweven[i.first] = curreven[i.first];
                    }
                }

                ll maxie = 0;
                ll maxio = 0;



                for(auto i : neweven){
                    maxie = max(maxie,i.second);
                }

                for(auto i : newodd){
                    maxio = max(maxio,i.second);
                }

                ll si = n-1;

                mini = min(mini,n-(maxie+maxio));

                odd[s[i]]++;

                currodd[s[i]]++;
            }
        }

        cout<<mini<<endl;

    }
}