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

    if(n==1){
        cout<<arr[0]<<endl;
        return;
    }

    int maxi=INT_MIN;

    int sum=0;

    if(arr[0]>=0){
        sum=arr[0];
        maxi=max(maxi,sum);
    }
   

    for(int i=1; i<n; i++){

        if(arr[i]<0 && sum==0){
            continue;
        }

        if(sum < 0){
            sum=0;
        }

        if(arr[i]%2==0 && arr[i-1]%2==0){

            if(arr[i]<0){
                sum=0;
            }else{
                sum = arr[i];
            }
           
        }else if(arr[i]%2!=0 && arr[i-1]%2!=0){
            if(arr[i]<0){
                sum=0;
            }else{
                sum = arr[i];
            }
        }else{
            sum += arr[i];
        }


        maxi = max(sum,maxi);
    }

    if(maxi==INT_MIN){
        int a= *max_element(arr.begin(),arr.end());
        cout<<a<<endl;
        return;
    }

    cout<<maxi<<endl;

}