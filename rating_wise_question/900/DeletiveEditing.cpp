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
    string a;
    string b;
    cin>>a;
    cin>>b;

    map<char,int> mp;

    int ia=a.size()-1;
    int ib=b.size()-1;

    while(1){
        if(ib==-1){
            cout<<"YES"<<endl;
            return;
        }

        if(ia==-1){
            cout<<"NO"<<endl;
            return;
        }

        if(a[ia]==b[ib]){
            if(mp[a[ia]]>0){
                cout<<"NO"<<endl;
                return;
            }
            ia--;
            ib--;
        }else{
            mp[a[ia]]++;
            ia--;
        }

    }
}