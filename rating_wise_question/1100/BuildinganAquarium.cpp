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

bool check(vector<int>& arr,int water,int mid){
    int ans=0;

    for(int i=0; i<arr.size(); i++){
        if(mid>=arr[i]){
            ans += mid-arr[i];

        }
    }

    if(ans <= water){
        return true;
    }else{
        return false;
    }
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

    int n,water;
    cin>>n>>water;

    vector<int> arr(n);
    inputV(arr,n);

    int sum=0;

    for(int i=0; i<n; i++){
        sum += arr[i];
    }


    int tall = *max_element(arr.begin(),arr.end());

    int a=(tall*n)-sum;

    if((water-a) >= 0){
        int b=water - a;
        cout<<tall + (b/n)<<endl;
        return;
    }else{
        int ans=1;
        int l=1;
        int r=tall;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(check(arr,water,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        cout<<ans<<endl;
    }
}