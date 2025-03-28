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

    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    inputV(arr,n);

    int sum=0;
    vector<int> prefix(n+1); 

    for(int i=0; i<n; i++){
        sum += arr[i];
        prefix[i+1]=sum;
    }

    while(k--){
        int l,r,c;
        cin>>l>>r>>c;

        int re=c*(r-l+1);
        

        int minus=prefix[r]-prefix[l-1];

        // for(int i=l-1; i<r; i++){
        //     minus += arr[i];
        // }

        if((sum-minus+re)%2!=0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}