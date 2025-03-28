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

    if(n%2!=0){
        cout<<"YES"<<endl;
        return;
    }

    // int root=sqrt(n);

    // int count=2;

    // while(count<=root){
    //     if(n%count==0){
    //         int num=n/count;

    //         if(count%2!=0){
    //             cout<<"YES"<<endl;
    //             return;
    //         }else if(num%2!=0){
    //             cout<<"YES"<<endl;
    //             return;
    //         }
    //     }

    //     count++;
    // }

    // cout<<"NO"<<endl;


    while(n!=1){
        n /= 2;
        if(n!=1){
        if(n%2!=0){
            cout<<"YES"<<endl;
            return;
        }
        }
    }

    cout<<"NO"<<endl;


}