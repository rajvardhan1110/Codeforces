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

    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    inputV(arr,n);

    sort(arr.begin(),arr.end());

    for(int i=0; i<n; i++){
        int check = arr[i] + k;

        int l=0;
        int r=n-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(arr[mid]==check){
                cout<<"YES"<<endl;
                return;
            }else if(arr[mid] > check){
                r=mid-1;
            }else{
                l=mid+1;
            }

        }
    }

    cout<<"NO"<<endl;
}