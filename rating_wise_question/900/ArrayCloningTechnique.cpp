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

    if(n==1){
        cout<<0<<endl;
        return;
    }

    int maxi=0;
    int count=1;

    sort(arr.begin(),arr.end());

    for(int i=0; i<n-1; i++){
        if(arr[i]!=arr[i+1]){
            maxi=max(maxi,count);
            count=1;
        }else{
            count++;
        }
    }

    maxi=max(maxi,count);

    int S=n;

    S -= maxi;
    int ans=0;

    // cout<<maxi<<endl;

    while(S>0){
        ans += 1;

        if(S-maxi >= 0){
            S -= maxi;
            ans += maxi;
        }else{
            ans += S;
            S=0;
        }

        maxi *= 2;

        if(S==0){
            break;
        }
    }

    cout<<ans<<endl;
}