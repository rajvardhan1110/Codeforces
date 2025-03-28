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
    int op,si;
    cin>>op>>si;

    vector<pair<int,int>> arr(op);

    for(int i=0; i<op; i++){
        int a,b;
        cin>>a>>b;
        arr[i].first=a;
        arr[i].second=b;
    }

    int bigperi=si*4*op;

    int count=0;

    for(int i=1; i<op; i++){
       int a=si-arr[i].first;
       int b=si-arr[i].second;

       bigperi -= 2*(a+b); 
    }

    cout<<bigperi<<endl;
}