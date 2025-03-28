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
    cin>>a;

    int ab=0;
    int ba=0;
    int n=a.size();

    for(int i=0; i<a.size()-1; i++){
        if(a[i]=='a' && a[i+1]=='b'){
            ab++;
        }else if(a[i]=='b' && a[i+1]=='a'){
            ba++;
        }
    }

    if(ab==ba){
        cout<<a<<endl;
        return;
    }

    if(ab>ba){
        if(a[0]=='a' && a[1]=='b'){
            a[0]='b';
            cout<<a<<endl;
            return;
        }else{
            a[n-1]='a';
            cout<<a<<endl;
            return;
        }
    }else{
        if(a[n-2]=='b' && a[n-1]=='a'){
            a[n-1]='b';
            cout<<a<<endl;
            return;
        }else{
            a[0]='a';
            cout<<a<<endl;
            return;
        }
    }




}