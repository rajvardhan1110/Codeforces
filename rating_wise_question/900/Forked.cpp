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

    int a,b;
    cin>>a>>b;

    int kx,ky;
    int qx,qy;
    cin>>kx>>ky>>qx>>qy;

    int ans=0;

    if(a==b){
        vector<int> x={-a,-a,a,a};
        vector<int> y={b,-b,b,-b};

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                int pkx=kx+x[i];
                int pky=ky+y[i];

                int pqx=qx+x[j];
                int pqy=qy+y[j];

                if(pkx==pqx && pky==pqy){
                    ans++;
                }
            }
        }
    }else{
        vector<int> x={a,a,-a,-a,b,b,-b,-b};
        vector<int> y={b,-b,b,-b,a,-a,a,-a};

        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                int pkx=kx+x[i];
                int pky=ky+y[i];

                int pqx=qx+x[j];
                int pqy=qy+y[j];

                if(pkx==pqx && pky==pqy){
                    ans++;  
                }
            }
        }

    }

    cout<<ans<<endl;

}