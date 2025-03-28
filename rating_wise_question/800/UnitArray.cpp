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

    int cn=0;
    int cp=0;

    for(int i=0; i<n; i++){
        if(arr[i]==1){
            cp++;
        }else{
            cn++;
        }
    }

    

    // if(diff<0 && cn%2!=0){
        
    //     if(diff%2!=0){
    //         cout<<abs(diff)<<endl;
            
    //     }else{
    //         cout<<abs(diff)+1<<endl;
    //     }

    //     return;
    // }else if(diff>=0 && cn%2==0){
    //     cout<<0<<endl;
    //     return;
    // }else if(diff>=0 && cn%2!=0){
    //     cout<<1<<endl;
    //     return;
    // }else{
    //     if(diff%2==0){
    //         cout<<abs(diff)<<endl;
            
    //     }else{
    //         cout<<abs(diff)+1<<endl;
    //     }

    //     return;
    // }
    int op=0;

   if(cp>=cn){
    if(cn%2!=0){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }

    return;
   }else{
        int op=cn-(n/2);

        if((n/2)%2!=0){
            op++;
        }

        cout<<op<<endl;
   }

    // cout<<op<<endl;
}   