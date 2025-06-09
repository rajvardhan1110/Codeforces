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

    vector<vector<int>> arr(n,vector<int> (n));

    set<int> set2;
    set<int> set1;

    for(int i=0; i<2*n; i++){
        set2.insert(i+1);
    }

    vector<int> miss;

    vector<int> ans(2*n,0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];

            ans[i+1+j+1-1] = arr[i][j];

            set1.insert(arr[i][j]);
        }
    }

    for (int num : set2) {
        if (set1.find(num) == set1.end()) {
           miss.push_back(num);
        }
    }

    int index=0;

    for(int i=0; i<2*n; i++){
        if(ans[i]==0){
            ans[i]=miss[index];
            index++;
        }
    }

    for(int i=0; i<2*n; i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}