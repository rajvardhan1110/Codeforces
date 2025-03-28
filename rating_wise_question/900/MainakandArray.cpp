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

    // vector<int> dummy=arr;

    // sort(dummy.begin(),dummy.end());

    // if(arr[0]==dummy[0] || arr[n-1]==dummy[n-1]){
    //     cout<<dummy[n-1]-dummy[0]<<endl;
    //     return;
    // }

    int maxi=0;
    int mini=INT_MAX;


    for(int i=0; i<n-1; i++){
        mini=min(mini,arr[i]);
    }

    maxi=max(arr[n-1]-mini,maxi);

    int maxi1=0;

    for(int i=n-1; i>0; i--){
        maxi1=max(maxi1,arr[i]);
    }

    maxi=max(maxi1-arr[0],maxi);

    for(int i=0; i<n-1; i++){
        maxi=max(maxi,arr[i]-arr[i+1]);
    }
    cout<<maxi<<endl;
}