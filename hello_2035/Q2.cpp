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
    int a,b;
    cin>>a>>b;

    vector<int> arr(a);
    inputV(arr,a);

    unordered_map<int,int> mp;

    for(int i=0; i<a; i++){
        mp[arr[i]]++;
    }

    vector<int> dummy;

    for(auto i:mp){
        dummy.push_back(i.second);
    }

    sort(dummy.begin(),dummy.end());

    int n=dummy.size();

    int ans=1;

    for(int i=0; i<n-1; i++){
        if(dummy[i]>b){
            dummy[i] -= b;
            break;
        }else{
            b -= dummy[i];
            dummy[i]=0;
            
        }
    }

    for(int i=0; i<n-1; i++){
        if(dummy[i]!=0){
            ans++;
        }
    }

    cout<<ans<<endl;
}