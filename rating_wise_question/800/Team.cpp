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
    int n;
    cin>>n;

    int cnt=0;

    while(n--){
        int a,b,c;
        cin>>a>>b>>c;

        int z=0;

        if(a==1){
            z++;
        }

        if(b==1){
            z++;
        }

        if(c==1){
            z++;
        }

        if(z>=2){
            cnt++;
        }


    }

    cout<<cnt<<endl;
}