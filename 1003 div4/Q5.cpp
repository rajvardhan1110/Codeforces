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

    vector<vector<int>> arr(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    vector<pair<int,int>> dum(n);

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum += arr[i][j];
        }

        dum[i]={sum,i};
    }

    sort(dum.begin(), dum.end(), greater<pair<int, int>>());

    // sort(dum.begin(),dum.end());
    
    // reverse(dum.begin(),dum.end());

    

    vector<int> ch;
    // ch.reserve(n * m);



    for(const auto& i:dum){
        int index=i.second;


        for(int z=0; z<m; z++){
            ch.push_back(arr[index][z]);

        }
    }

    // printV(ch,n*m);

    int sol=0;
    int ans=0;

    for(int i=0; i<n*m; i++){
        sol += ch[i];
        ans += sol;
    }

    cout<<ans<<endl;

    
}