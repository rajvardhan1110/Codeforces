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

    string s;
    cin>>s;

    int count = 0;

    for(int i=0 ;i<s.size(); i++){
        if(s[i] >= 'A' && s[i]<='Z'){
            count++;
        }
    }

    if(count==s.size()){
        for(int i=0; i<s.size(); i++){
            int a = s[i] - 'A';
            s[i] = 'a' + a;
        }
    }

    if(count==s.size()-1 && s[0]>='a' && s[0]<='z'){
        int b = s[0] - 'a';
        s[0] = 'A' + b;

        for(int i=1; i<s.size(); i++){
            int a = s[i] - 'A';
            s[i] = 'a' + a;
        }
        
    }

    cout<<s<<endl;
}