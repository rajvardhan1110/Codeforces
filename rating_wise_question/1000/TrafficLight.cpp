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
    char c;
    cin>>n;

    cin>>c;

    string s;
    cin>>s;


//     vector<int> start;
//     vector<int> dest;

//    for(int i=0; i<n; i++){
//     if(s[i]==c){
//         start.push_back(i+1);
//     }else if(s[i]=='g'){
//         dest.push_back(i+1);
//     }
//    }

//     int count=INT_MAX;

//     for(int i=0; i<start.size(); i++){
//         for(int j=0; j<dest.size(); j++){
//             if(start[i] < dest[j]){
//                 count=min(count,dest[j]-start[i]);
//             }else{
//                 count=min(count,n-start[i]+dest[j]);
//             }

//         }
//     }

//     cout<<count<<endl;

if(c=='g'){
    cout<<0<<endl;
    return;
}

    vector<int> nextG(n,INT_MAX);
    int lastG=INT_MAX;

    for(int i=n-1; i>=0; i--){
        if(s[i]=='g'){
            lastG=i;
        }

        nextG[i]=lastG;
    }

    int ans=INT_MIN;

    for(int i=0; i<n; i++){
        if(s[i]==c){
            int a;
            if(nextG[i]==INT_MAX){
                a=n-i+nextG[0];
            }else{
                a=nextG[i]-i;
            }

            ans=max(ans,a);
            // cout<<ans<<endl;
        }

        
    }

   

    cout<<ans<<endl;
}