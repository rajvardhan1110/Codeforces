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

    vector<int> pre(n);
    vector<int> suf(n);

    map<int,int> mpl;
    map<int,int> mpr;

    int sum=0;

    for(int i=0; i<n; i++){
        sum += arr[i];

        pre[i] = sum;
    }

    sum = 0;

    for(int i=n-1; i>=0; i--){
         sum += arr[i];
         suf[i] = sum;
    }

    for(int i=0; i<n; i++){
        mpl[pre[i]] = i+1;
        mpr[suf[i]] = i+1;
    }

    int ans=INT_MIN;

    for(int i=0; i<n; i++){
        int a=pre[i];

        if(mpr.find(a) != mpr.end()){
            int index = mpr[a];

            if(index - (i+1) > 0){
                int z=n-index+1+i+1;
                ans = max(ans,z);
            }
        }
    }


    for(int i=0; i<n; i++){
        int a=suf[i];

        if(mpl.find(a) != mpl.end()){
            int index = mpl[a];

            if((i+1) -index > 0){
                int z=n-(i+1)+1+index;
                ans = max(ans,z);
            }
        }
    }

    if(ans == INT_MIN){
        cout<<0<<endl;
        return;
    }

    cout<<ans<<endl;



}