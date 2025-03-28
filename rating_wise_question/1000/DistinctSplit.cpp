#include <bits/stdc++.h>
using namespace std;
#define int long long

void inputV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i];
    }
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    // Add your code here
    int n;
    cin>>n;

    string si;
    cin>>si;

    // map<int,int> mp;
    // map<int,bool> b;

    // for(int i=0; i<n; i++){
    //     mp[s[i]]++;
    //     b[s[i]]=false;
    // }

    // int count=mp.size();

    // for(int i=0; i<n-1; i++){
    //     mp[s[i]]--;

    //     if(mp[s[i]]>0 && b[s[i]]==false){
    //         count++;
    //     }

    //     b[s[i]]=true;
    // }

    set<int> s;
    set<int> e;

    vector<int> ss(n);
    vector<int> ee(n);

    for(int i=0; i<n-1; i++){
        s.insert(si[i]);

        ss[i]=s.size();
    }

    for(int i=n-1; i>0; i--){
        e.insert(si[i]);

        ee[i]=e.size();
    }

    int ans=INT_MIN;
    
    for(int i=0; i<n-1; i++){
        int count=ss[i] + ee[i+1];

        ans = max(ans,count);
    }

   

    cout<<ans<<endl;
}