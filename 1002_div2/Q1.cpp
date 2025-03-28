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

    vector<int> arr1(n);
    vector<int> arr2(n);

    inputV(arr1,n);
    inputV(arr2,n);

    map<int,int> mp1;
    map<int,int> mp2;

    for(int i=0; i<n; i++){
        mp1[arr1[i]]++;
        mp2[arr2[i]]++;
    }

    if((mp1.size()==1 && mp2.size()<3) || (mp1.size()<3 && mp2.size()==1)){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}