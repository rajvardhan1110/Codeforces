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

    vector<int> arr(n);

    inputV(arr,n);

    vector<int> ans;

    map<int,vector<int>> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]].push_back(i+1);
    }

    for(auto i: mp){
        if(i.second.size() == 1){
            cout<<-1<<endl;
            return;
        }

        int s=i.second.size();

        ans.push_back(i.second[s-1]);

        for(int j=0; j<s-1; j++){
            ans.push_back(i.second[j]);
        }
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}