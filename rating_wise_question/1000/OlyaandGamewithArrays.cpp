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

    vector<vector<int>> mp(n,vector<int>(2));

    for(int i=0; i<n; i++){
        int m;
        cin>>m;

        vector<int> arr(m);
        inputV(arr,m);

        sort(arr.begin(),arr.end());

        mp[i][0]=arr[0];
        mp[i][1]=arr[1];

    }

    // for(auto i:mp){
    //     for(auto p:i){
    //         cout<<p<<" ";
    //     }

    //     cout<<endl;
    // }

    // cout<<endl;
    // cout<<endl;

    int count=0;

    for(int i=0; i<n; i++){
        int ans=0;
        
        int fir=mp[i][0];

        for(int j=0; j<n; j++){
            if(i!=j){
                ans += mp[j][1];
            }
            
            fir=min(fir,mp[j][0]);

        }

        //cout<<fir<<endl;

        ans +=fir;

        count =max(count,ans);
    }

    cout<<count<<endl;

}