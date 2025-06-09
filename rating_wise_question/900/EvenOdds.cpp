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
    int n,k;
    cin>>n>>k;

    if(n % 2 == 0){
        int a = n / 2;

        if(k <= a){
            cout<<2*k - 1<<endl;
            return;
        }else{
            cout<<2*(k-a)<<endl;
            return;
        }
    }else{
        int a = n/2 + 1;

        if(k <= a){
            cout<<2*k - 1<<endl;
        }else{
            cout<<(k-a)*2<<endl;
        }
    }
}