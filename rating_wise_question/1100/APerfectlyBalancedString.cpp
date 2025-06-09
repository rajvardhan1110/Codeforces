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
    string s;
    cin >> s;

    int n = s.size();

    set<char> se;

    int k=n;

    for (int i = 0; i < n; i++) {
        if(se.find(s[i]) == se.end()){
            se.insert(s[i]);
        }else{
            k=i;
            break;
        }
    }

    string a="";

    for(int i=0; i<k; i++){
        a+=s[i];
    }

    for(int i=k; i<n; i += k){
        string b="";

        for(int j=i; j<n && j<i+k; j++){
            b+=s[j];
        }

        if(a!=b){
            cout<<"NO"<<endl;
            return;
        }
    }

    if(n % a.size() != 0){
        int z = n % a.size();
        int start = n - z;

        int c=0;

        for(int i=start; i<n; i++){
            if(s[i] != a[c]){
                cout<<"NO"<<endl;
                return;
            }
            c++;
        }
    }

    cout<<"YES"<<endl;


}