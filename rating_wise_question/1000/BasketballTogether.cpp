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
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    inputV(arr,n);

    int s=0;
    int e=n-1;

    sort(arr.rbegin(),arr.rend());

    int count=0;

    while(s<=e){
        int d=k/arr[s];
        if(k%arr[s]!=0 || k%arr[s]==0){
            d++;
        }

        d--;

        if(e-d < s){
            break;
        }

        e -= d;

        count++;
        s++;


    }

    cout<<count<<endl;

}