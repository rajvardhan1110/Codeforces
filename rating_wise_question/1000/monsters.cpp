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

    vector<int> arr(n);
    inputV(arr,n);

    vector<pair<int,int>> v;
    vector<int> dummy(n);

    for(int i=0; i<n; i++){
        if(arr[i]%m==0){
            dummy[i]=m;
        }else{
            dummy[i]=arr[i]%m;
        }
    }

    for(int i=0; i<n; i++){
       v.push_back({dummy[i],-i});
    }

    sort(v.begin(),v.end());

    for(int i=v.size()-1; i>=0; i--){
        cout<<abs(v[i].second) + 1<<" ";
    }

    cout<<endl;
}