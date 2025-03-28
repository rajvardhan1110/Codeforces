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

    vector<int> b;
    vector<int> c;

    sort(arr.begin(),arr.end());
    int num=arr[n-1];

    for(int i=n-1; i>=0; i--){
        if(arr[i]==num){
            c.push_back(arr[i]);
        }else{
            b.push_back(arr[i]);
        }
    }

    if(b.size()==0){
        cout<<-1<<endl;
        return;
    }

    cout<<b.size()<<" "<<c.size()<<endl;
    for(int i=0; i<b.size(); i++){
        cout<<b[i]<<" ";
    }

    cout<<endl;

    for(int i=0; i<c.size(); i++){
        cout<<c[i]<<" ";
    }

    cout<<endl;


}