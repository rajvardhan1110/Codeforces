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

    vector<int> arr(a);
    inputV(arr,a);

    int sum=0;
    // int sum2=0;

    int mini=0;
    int maxi=0;

    // //for mini
    // for(int i=0; i<a; i++){
    //     sum1 += arr[i];
    //     int wor=sum1/b;
    //     int wr=ceil(static_cast<double>(sum1) / b);

    //     if(wor!=wr){
            
    //         // sum1 += arr[i];
    //     }else{
    //         mini += wor;
    //         sum1=0;
    //     }


    // }

    // mini += round(static_cast<double>(sum1) / b);

    // //for maxi
    // for(int i=0; i<a; i++){
    //     sum2 += arr[i];
    //     int wor=sum2/b;
    //     int wr=ceil(static_cast<double>(sum2) / b);

    //     if(wor!=wr){
            
    //         maxi += wr;
    //         sum2=0;
    //     }else{
    //         // sum2 += arr[i];
    //     }


    // }

    // maxi += round(static_cast<double>(sum2) / b);

    // cout<<mini<<" "<<maxi<<endl;

    for(int i=0; i<a; i++){
        sum += arr[i];

        maxi += ceil(static_cast<double>(arr[i]) / b);
    }

    mini += ceil(static_cast<double>(sum) / b);

    cout<<mini<<" "<<maxi<<endl;

}