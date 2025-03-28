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

    if((n&(n-1))==0 || (n&(n+1))==0){
        cout<<-1<<endl;
        return;
    }

    int last=n&1;
    n=n>>1;
    int count=0;

    while(n){
        int a=n&1;

        if(a!=last){
            break;
        }

        last=a;

        n=n>>1;

        count++;
    }

    int a=count+1;

    int ans=0;

    for(int i=0; i<=a; i++){
        ans += pow(2,i);
    }

    cout<<ans<<endl;


}