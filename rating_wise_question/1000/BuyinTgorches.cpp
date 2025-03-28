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

    int x,y,k;
    cin>>x>>y>>k;

    int count = k;

    int divide= x-1;

    int need= y*k - 1;

   int sticksC = need / divide + (need%divide != 0);

   int currsticks = sticksC*divide + 1 - y*k;

    if(currsticks >= k ){
        cout<<sticksC+count<<endl;
    }else{
       int needs = k- currsticks;
        sticksC += needs/divide + (needs%divide != 0);
        cout<<sticksC+count<<endl;
    }

   

    

}