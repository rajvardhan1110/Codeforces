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
    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    // Add your code here

    vector<int> arr(3);

    inputV(arr,3);

    // sort(arr.begin(),arr.end());

    int count = 0;

    for(int i=0; i<3; i++){
        if(arr[i]==1){
            count++;
        }
    }

    if(count==3){
        cout<<3<<endl;
        return;
    }

    // if(count > 0){
    //     cout<<(arr[0]+arr[1]) * arr[2]<<endl;
    //     return;
    // }

    // cout<<arr[0]*arr[1]*arr[2]<<endl;

    if(arr[0]==1 && arr[1]==1){
        cout<<2*arr[2]<<endl;
    }else if(arr[0]==1 && arr[2]==1 ){
        cout<<2+arr[1]<<endl;
    }else if(arr[2]==1 && arr[1]==1){
        cout<<2*arr[0]<<endl;
    }else if(arr[0]==1){
        cout<<(1+arr[1])*arr[2]<<endl;
    }else if(arr[2]==1){
        cout<<(1+arr[1])*arr[0]<<endl;
    }else if(arr[1]==1){
        int mini = min(arr[0],arr[2]);
        int maxi = max(arr[0],arr[2]);

        cout<<(mini+1)*maxi<<endl;
    }else{
        cout<<arr[0]*arr[1]*arr[2]<<endl;
    }




}