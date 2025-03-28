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

    // for(int i=1; i<n-1; i++){
    //     if(arr[i]>arr[i-1] && arr[i]<arr[i+1]){
    //         continue;
    //     }else if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            
    //             if(arr[i-1]<arr[i+1]){
    //                 swap(arr[i],arr[i+1]);
    //             }else{
    //                 cout<<"NO"<<endl;
    //                 return;
    //             }
            
    //     }else{
    //         cout<<"NO"<<endl;
    //         return;
    //     }


    // }

    bool flag=true;

    while(flag){
        flag=false;

        for(int i=1; i<n-1; i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                flag=true;
            }
        }
    }

    vector<int> dummy=arr;
    sort(dummy.begin(),dummy.end());

    if(dummy==arr){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    
}