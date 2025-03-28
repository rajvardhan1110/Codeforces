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

    int count=0;

    vector<int> arr(n);
    inputV(arr,n);

    if(n==1){
        cout<<0<<endl;
        return;
    }


    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            continue;
        }else{
            while(arr[i]>=arr[i+1]){
                if(arr[i]==0 && arr[i+1]==0){
                    cout<<-1<<endl;
                    return;
                }else{
                    arr[i] = arr[i]/2;
                    count++;
                }
            }
        }
    }

    cout<<count<<endl;
}