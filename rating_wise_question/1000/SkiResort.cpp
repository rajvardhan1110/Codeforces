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
    int n,k,t;
    cin>>n>>k>>t;

    vector<int> arr(n+1);

   for(int i=1; i<=n; i++){
    cin>>arr[i];
   }

    int count=0;

    stack<int> st;

    st.push(0);

    for(int i=1; i<=n; i++){
        if(arr[i] > t){
            st.push(i);
        }
    }

    st.push(n+1);

    while(st.top()!=0){
        int a=st.top();
        st.pop();

        int b=(a-1)-(st.top()+1)+1;

        if(b>=k){
            int d=k;
            while(d<=b){
                count += b - d + 1;

                d++;
            }
        }
    }

    cout<<count<<endl;
}