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
    int a,b,c;
    cin>>a>>b>>c;

    if((2*b-c)>0 && (2*b-c)%a==0){
        cout<<"YES"<<endl;
    }else if((2*b-a)>0 && (2*b-a)%c==0){
        cout<<"YES"<<endl;
    }else if((a+c)%2==0 && (a+c)/2 >0 && ((a+c)/2)%b==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}