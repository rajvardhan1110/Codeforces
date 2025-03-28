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

    vector<int> even;
    vector<int> odd;

    sort(arr.rbegin(),arr.rend());

    // for(int i=0; i<n; i++){
    //     if(arr[i]%2==0){
    //         even.push_back(arr[i]);
    //     }else{
    //         odd.push_back(arr[i]);
    //     }
    // }

    int alice=0;
    int bob=0;

    // bool flag=true;

    // int oc=0;
    // int ec=0;

    // while(oc<odd.size() && ec<even.size()){
    //     alice += even[ec];
    //     ec++;

    //     bob += odd[oc];
    //     oc++;
    // }

    // if(ec==even.size()){
    //     oc++;
    //     while(oc<odd.size()){
    //         bob +=odd[oc];
    //         oc += 2;
    //     }
    // }else if(oc==odd.size()){
    //     while(ec<even.size()){
    //         alice +=even[ec];
    //         ec += 2;
    //     }
    // }



     for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  
            if (arr[i] % 2 == 0) {
                alice += arr[i]; 
            }
        } else {  
            if (arr[i] % 2 == 1) {
                bob += arr[i];  
            }
        }
    }

    if(alice>bob){
        cout<<"Alice"<<endl;
    }else if(alice<bob){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Tie"<<endl;
    }

    
}