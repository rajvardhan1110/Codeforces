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

    // sort(arr.begin(),arr.end());

    // int a=arr[0];

    // // if(a>2){
    // //     cout<<"NO"<<endl;
    // //     return;
    // // }

    // for(int i=1; i<n; i++){
    //     a=__gcd(a,arr[i]);

    //     if(a > i+1){
    //         cout<<"No"<<endl;
    //         return;
    //     }
    // }

    // cout<<"Yes"<<endl;

    bool flag=false;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(__gcd(arr[i],arr[j])<=2){
                flag=true;
                break;
            }
        }
    }

    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}