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
    int n,c;
    cin>>n>>c;

    vector<int> arr(n);
    inputV(arr,n);

    int ans = 0;

    // vector<pair<int,int>> p;
    vector<int> pa;

    for(int i=0; i<n; i++){
        // p.push_back({arr[i],i+1});
        pa.push_back(arr[i] + (i+1));

    }

    // sort(p.begin(),p.end());
    sort(pa.begin(),pa.end());

    int a = 0;

    while(a<n && pa[a] <= c){
        ans++;
        // c -= (p[a].first + p[a].second);
        c -= pa[a];
        a++;
    }

    cout<<ans<<endl;
}