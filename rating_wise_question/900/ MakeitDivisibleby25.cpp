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

int ops(string& digit,string& num){
    char x=digit[0];
    char y=digit[1];

    int j=num.size()-1;
    int steps=0;

    while(j>=0 && num[j]!=y){
        j--;
        steps++;
    }

    int i=j-1;

    while(i>=0 && num[i]!=x){
        i--;
        steps++;
    }

    return steps;
}

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

    string s=to_string(n);

    vector<string> digits={"00","25","50","75"};

    int ans=INT_MAX;

    for(auto digit: digits){
        int mini=ops(digit,s);

        ans=min(ans,mini);
    }

    cout<<ans<<endl;
}