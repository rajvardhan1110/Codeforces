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
    vector<int> a(n);
    vector<int> b(n);

    inputV(a,n);
    inputV(b,n);

    map<int,int> mp1;
    map<int,int> mp2;

    int count=1;

    for(int i=0; i<n-1; i++){
        if(a[i]==a[i+1]){
            count++;
            
        }else{
            mp1[a[i]] = max(mp1[a[i]], count);
            count = 1;
        }
    }

    mp1[a[n-1]] = max(mp1[a[n-1]], count);

    count=1;

    for(int i=0; i<n-1; i++){
        if(b[i]==b[i+1]){
            count++;
            
        }else{
            mp2[b[i]] = max(mp2[b[i]], count);
            count = 1;
        }
    }

    mp2[b[n-1]] = max(mp2[b[n-1]], count);

    int maxi=0;

    for(auto i:mp1){
        maxi=max(maxi,mp2[i.first]+i.second);
    }

    for(auto i:mp2){
        maxi=max(maxi,mp1[i.first]+i.second);
    }

    cout<<maxi<<endl;
}