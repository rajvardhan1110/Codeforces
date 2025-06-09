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
    vector<int> b(n);

    inputV(a,n);
    inputV(b,n);

    set<int> s;

    int minus=0;
    int c=-1;

    for(int i=0; i<n; i++){
        if(b[i]==-1){
            minus++;
        }else{
            s.insert(a[i]+b[i]);
            c = a[i]+b[i];
        }
    }

    if(s.size() > 1){
        cout<<0<<endl;
        return;
    }

    if(minus==n){
        vector<int> d = a;
        sort(d.begin(),d.end());

        cout<<k+d[0]-d[n-1]+1<<endl;
        return;
    }

    bool flag = true;

    
    for(int i=0; i<n; i++){
        if(b[i]==-1){
            
            int z = c - a[i];

            if(z<0){
                cout<<0<<endl;
                return;
            }

            if(z > k){
                cout<<0<<endl;
                return;
            }

            
        }
    }

    cout<<1<<endl;



}