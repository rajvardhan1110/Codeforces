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
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n);

    for(int i=0; i<n; i++){
        vector<int> dummy(m);
        inputV(dummy,m);

        sort(dummy.begin(),dummy.end());

        arr[i]=dummy;
    }

    vector<int> sol(n);

    for(int i=0; i<n; i++){
        vector<int> ch(n);
        ch =arr[i];
        for(int j=1; j<m; j++){
            if(ch[j]!=ch[j-1]+n){
                cout<<-1<<endl;
                return;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j][0]==i){
                sol[i]=j+1;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<sol[i]<<" ";
    }

    cout<<endl;
}