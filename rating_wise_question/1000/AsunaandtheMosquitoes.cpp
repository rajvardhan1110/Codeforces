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

    vector<int> odd;
    vector<int> even;

    for(int i=0; i<n; i++){
        if(arr[i]%2==0){
            even.push_back(arr[i]);
        }else{
            odd.push_back(arr[i]);
        }
    }

    int maxi_odd=0;
    int maxi_even=0;

    int sum_odd=0;
    int sum_even=0;

    

    for(int i=0; i<odd.size(); i++){
        maxi_odd = max(odd[i],maxi_odd);
        sum_odd += odd[i];
    }

    for(int i=0; i<even.size(); i++){
        maxi_even = max(even[i],maxi_even);
        sum_even += even[i];
    }

    if(odd.size()==n){
        cout<<maxi_odd<<endl;
        return;
    }

    if(even.size()==n){
        cout<<maxi_even<<endl;
        return;
    }

    cout<<max(maxi_odd + sum_even, maxi_even + sum_odd)<<endl;


}