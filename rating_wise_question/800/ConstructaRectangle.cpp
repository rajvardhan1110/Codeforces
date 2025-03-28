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

   vector<int> arr(3);
    inputV(arr,3);
    // map<int,int> mp;
    // int maxi=0;

    // for(int i=0; i<3; i++){
    //     mp[arr[i]]++;
    //     maxi = max(maxi,arr[i]);
    // }

    // if(mp.size()==2){
    //     for(auto i:mp){
    //         if(i.second==1 && i.first%2==0){
    //             cout<<"YES"<<endl;
    //             return;
    //         }
    //     }
    // }else if(mp.size()==1){
    //     for(auto i:mp){
    //         if(i.second%2==0){
    //             cout<<"YES"<<endl;
    //             return;
    //         }
    //     }
    // }else{
    //     int dummy=maxi;
    //     for(int i=0; i<3; i++){
    //         if(arr[i]!=dummy){
    //             maxi -= arr[i];
    //         }
    //     }

    //     if(maxi == 0){
    //         cout<<"YES"<<endl;
    //         return;
    //     }
    // }

    // cout<<"NO"<<endl;


    // int sum=0;
    // for(int i=0; i<3; i++){
    //     sum += arr[i];
    // }

    // if(sum%2==0){
    //     cout<<"YES"<<endl;
    // }else{
    //     cout<<"NO"<<endl;
    // }

    sort(arr.begin(),arr.end());

    if(arr[0]==arr[1] && arr[2]%2==0){
        cout<<"YES"<<endl;
    }else if(arr[2]==arr[1] && arr[0]%2==0){
        cout<<"YES"<<endl;
    }else if(arr[0]+arr[1]==arr[2]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}