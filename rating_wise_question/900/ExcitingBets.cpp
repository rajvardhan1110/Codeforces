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

    int a,b;
    cin>>a>>b;

    if(a==b){
        cout<<0<<" "<<0<<endl;
        return;
    }

    int f=abs(a-b);

    // int s=0;

    // if(a%f==0 && b%f==0){
    //     cout<<f<<" "<<0<<endl;
    //     return;
    // }

    // int y=a%f;
    // int z=b%f;

    // int c1=f-y;

    // if(c1>y && a-f!=0 && b-f!=0){
    //     s=f;
    // }else{
    //     s=c1;
    // }

    // cout<<f<<" "<<s<<endl;


    int r=a%f;

    cout<<f<<" "<<min(r,f-r)<<endl;



}