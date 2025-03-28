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

    int count=0;

    vector<int> dummy=arr;

    sort(dummy.rbegin(),dummy.rend());



    for(int i=0; i<n; i++){
        int a=(i/2) + 1;

        count += 2*a*dummy[i];
    }

    map<int,queue<int>> mp;

    for(int i=0; i<n; i++){
        mp[dummy[i]].push(i+1);
    }

    vector<int> ans(n+1);
    ans[0]=0;

    for(int i=0; i<n; i++){
        int x=mp[arr[i]].front();

        if(x%2!=0){
            ans[i+1] = -((x/2)+1);
        }else{
            ans[i+1]=x/2;
        }

        mp[arr[i]].pop();
    }

    cout<<count<<endl;

    for(int i=0; i<=n; i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;


}