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

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    inputV(a,n);

    vector<int> b(n);
    inputV(b,n);

    int sum=0;

    int ans=0;

    int jast=INT_MIN;

    int upto = min(n,k);

    vector<int> maxi(upto);

    for(int i=0; i<upto; i++){
        sum += a[i];

        jast = max(jast,b[i]);
        maxi[i]=jast;
    }

    for(int i=upto-1; i>=0; i--){
        int z=k-(i+1);
        int y=sum+(z*maxi[i]);


        ans = max(ans,y);

        sum -= a[i];
    }

    cout<<ans<<endl;
}