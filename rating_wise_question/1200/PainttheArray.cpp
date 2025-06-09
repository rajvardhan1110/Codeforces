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
    cin>>n;

    vector<int> arr(n);
    inputV(arr,n);

    int a=0,b=0;

    for(int i=0; i<n; i++){
        if(i%2==0){
            a = __gcd(a,arr[i]);
        }else{
            b = __gcd(b,arr[i]);
        }
    }

    bool aa=true;
    bool bb=true;

    for(int i=0; i<n; i += 2){
        if(arr[i]%b==0){
            aa=false;
            break;
        }
    }

    if(aa){
        cout<<b<<endl;
        return;
    }


    for(int i=1; i<n; i += 2){
        if(arr[i]%a==0){
            bb=false;
            break;
        }
    }

    if(bb){
        cout<<a<<endl;
        return;
    }

    cout<<0<<endl;

}