#include <bits/stdc++.h>
using namespace std;
#define int long long

int MAX = 1e6 + 1;
vector<bool> prime(MAX,true);


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

// bool cprime(int n){
//     for(int i=2; i*i < n; i++){
//         if(n%i == 0){
//             return false;
//         }
//     }

//     return true;
// }

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    createsieve(prime, MAX);

    while (t--) {
        solve();
    }
}

void solve() {
    // Add your code here
    int n;
    cin>>n;

    if(n==1){
        cout<<"NO"<<endl;
        return;
    }

    // int a = sqrt(n);

    // if(a*a != n){
    //     cout<<"NO"<<endl;
    // }else{
    // //    for(int i=2; i*i < n; i++){
    // //     if(n%i == 0){
    // //         cout<<"NO"<<endl;
    // //         return;
    // //     }
    // // }

    // //     cout<<"YES"<<endl;

    //     if(prime[a]){
    //         cout<<"YES"<<endl;
    //     }else{
    //         cout<<"NO"<<endl;
    //     }
    // }

    // cout<<prime[2]<<endl;

    int a = sqrt(n);
    if (a * a == n && prime[a]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}   