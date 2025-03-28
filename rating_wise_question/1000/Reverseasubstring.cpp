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
    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    // Add your code here
   
    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<int> arr(n,INT_MAX);
    vector<int> dummy(n);
    stack<int> st;

    for(int i=0; i<n; i++){
        dummy[i] = s[i] - 'a';
    }

    for(int i=n-1; i>=0; i--){
        if(!st.empty() && dummy[st.top()] < dummy[i]){
            arr[i] = st.top();
        }

        while(!st.empty() && dummy[st.top()] > dummy[i] ){
            st.pop();
        }

        st.push(i);
    }

   int l=-1;
   int r=-1;

    for(int i=0; i<n; i++){
        if(arr[i]!=INT_MAX){
            l=i;
            r=arr[i];
            break;
        }
    }

    if(l==-1 && r==-1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<l+1<<" "<<r+1<<endl;
    }


// for(int i=0; i<n-1; i++){
//     if(s[i] > s[i+1]){
//         cout<<"YES"<<endl;
//         cout<<i+1<<" "<<i+2<<endl;
//         return;
//     }
// }

// cout<<"NO"<<endl;
    
}