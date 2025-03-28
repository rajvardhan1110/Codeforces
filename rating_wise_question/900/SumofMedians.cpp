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

    vector<int> arr(a*b);
    inputV(arr,a*b);

    // int r=ceil(static_cast<double> (a)/2);

    int n=a*b;
    // int sum=0;

    // int x=b-r+1;

    // while(b){
    //     n -= x;

    //     sum += arr[n-1];

    //     b--;

    // }

    // cout<<sum<<endl;

    int sum=0;

    int r=ceil(static_cast<double> (a)/2);
    int x=a-r+1;

    int count=1;

    for(int i=n-1; i>=0; i--){
        
        

        if(count==x){
            sum += arr[i];
            count=1;
            b--;
        }else{
            count++;
        }

        
        

        if(b==0){
            break;
        }
    }

    cout<<sum<<endl;


}