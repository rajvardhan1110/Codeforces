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

    int n,s,e;
    cin>>n>>s>>e;


    vector<pair<int,int>> arr;

    for(int i=0; i<n; i++){
        int a;
        int b;
        cin>>a>>b;

        arr.push_back({a,b});
    }

    sort(arr.begin(),arr.end());

    if(arr[0].first >= s){
        cout<<"YES"<<endl;
        return;
    }

    for(int i=0; i<n-1; i++){
        if(arr[i+1].first - arr[i].second >= s){
            cout<<"YES"<<endl;
            return;
        }
    }

    if(e - arr[n-1].second >= s){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;
}