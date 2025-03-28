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

    int count=0;

    // if(n==1){
    //     cout<<0<<endl;
    //     return;
    // }
    // int s=-1;

    // int index=-1;

    // for(int i=0; i<n-1; i++){
    //     if(arr[i]!=arr[i+1]){
    //         index=i;
    //         break;
    //     }
    // }

    // if(index==-1){
    //     cout<<0<<endl;
    //     return;
    // }

    // if(arr[index+1]>arr[index]){
    //     s=arr[index] + k;
    // }else if(arr[index+1]<arr[index]){
    //     s=arr[index] -k;
    // }

    // for(int i=1; i<n; i++){
    //     if(abs(s-arr[i]) > k){
            
    //         if(i!=n-1){

    //         if(arr[i+1]==arr[i]){
    //             continue;
    //         }else if(arr[i+1]>arr[i]){
    //             s=arr[i] + k;
    //         }else if(arr[i+1]<arr[i]){
    //             s=arr[i] - k;
    //         }
    //         }

    //         count++;
    //     }
    // }


    vector<int> prev={arr[0]-k,arr[0]+k};

    for(int i=1; i<n; i++){
        vector<int> curr={arr[i]-k,arr[i]+k};

        vector<int> overlap={max(prev[0],curr[0]),min(prev[1],curr[1])};

        if(overlap[0] > overlap[1]){
            count++;
            prev=curr;
        }else{
            prev=overlap;
        }
    }

    cout<<count<<endl;
}