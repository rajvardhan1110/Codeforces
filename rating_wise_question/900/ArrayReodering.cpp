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

    int ans=0;

    // int odd=0;
    vector<int> odd;
    // int even=0;
    vector<int> even;

    vector<int> dummy;

    for(int i=0; i<n; i++){
        if(arr[i]%2==0){
            even.push_back(arr[i]);
        }else{
           odd.push_back(arr[i]);
        }
    }

    for(int i=0; i<even.size(); i++){
        dummy.push_back(even[i]);
    }

    for(int i=0; i<odd.size(); i++){
        dummy.push_back(odd[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(__gcd(dummy[i],2*dummy[j]) > 1){
                ans++;
            }
        }
    }


   

    cout<<ans<<endl;
}