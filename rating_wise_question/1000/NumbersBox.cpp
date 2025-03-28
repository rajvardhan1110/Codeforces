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
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int> (m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int ans=0;

    int count=0;
    int mini=INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans += abs(arr[i][j]);

            mini = min(mini,abs(arr[i][j]));

            if(arr[i][j] < 0){
                count++;
            }
        }
    }


    if(count%2==0){
        cout<<ans<<endl;
    }else{
        cout<<ans-2*abs(mini)<<endl;
    }

}