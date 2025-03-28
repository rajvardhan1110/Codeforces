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

    // int mini=INT_MAX;
    // int maxi=0;

    // int a=n;
    // int b=n;

    if(n%2!=0){
        cout<<-1<<endl;
        return;
    }

    //for mini
    // while(a!=0){
    //     if(a%4==0){
    //         mini++;
    //         a -= 4;
    //     }else if(a%6==0){
    //         mini++;
    //         a -= 6;
    //     }
    // }

    // for(int i=0; i<=n/6; i++){
    //     int rem=n-i*6;
    //     if(rem%4==0){
    //         mini=min(mini,i+(rem/4));
    //     }

    // }


    //for maxi
    // while(b!=0){
    //     if(b%6==0){
    //         maxi++;
    //         b -= 6;
    //     }else if(b%4==0){
    //         maxi++;
    //         b -= 4;
    //     }
    // }

    // for(int i=0; i<=n/4; i++){
    //     int rem=n-i*4;
    //     if(rem%6==0){
    //         maxi=max(maxi,i+(rem/6));
    //     }

    // }

    // if (mini == INT_MAX || maxi == 0) {
    //     cout << -1 << endl; 
    // } else {
    //     cout << mini << " " << maxi << endl;
    // }

    n /= 2;

    if(n==1){
        cout<<-1<<endl;
    }else{
        cout<<(n/3) + (n%3!=0 ? 1 : 0)<<" "<< n/2 <<endl;
    }

}