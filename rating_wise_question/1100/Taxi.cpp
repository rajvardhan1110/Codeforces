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
    int t=1;
    // cin >> t;

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

    vector<int> ch(5,0);

    for(auto i: arr){
        ch[i]++;
    }

    int ans = 0;

    ans += ch[4];

    int mini = min(ch[1],ch[3]);
    ans += mini;

    // cout<<mini<<endl;

    ch[1] -= mini;
    ch[3] -= mini;

    ans += ch[2] / 2;

    if(ch[2] % 2 != 0 ){
        ch[2] = 1;
    }else{
        ch[2] = 0;
    }

    if(ch[3] != 0){
        ans += ch[3];
    }

    // mini = min(ch[1],ch[2]);

    // ans += mini;

    // ch[1] -= mini;
    // ch[2] -= mini;

    // if(ch[1] != 0){
    //     ans += ch[1] / 4;

    //         if(ch[1] % 4 != 0){
    //             ans++;
    //         }
    // }

    // if(ch[2] != 0){
    //     ans += ch[2];
    // }


    if(ch[1] > 1 && ch[2] != 0){
        ans++;

        ch[1] -= 2;
        ch[2] = 0;
    }

    if(ch[1] == 1 && ch[2] != 0){
        ans++;

        ch[1] = 0;
        ch[2] = 0;
    }

    if(ch[1] != 0){
        ans += ch[1] / 4;

            if(ch[1] % 4 != 0){
                ans++;
            }
    }

    if(ch[2] != 0){
        ans += ch[2];
    }

    cout<<ans<<endl;

    // int ans = 0;

    // for(auto i : arr){
    //     ans += i;
    // }

    // int sol=0;
    // sol = ans / 4;

    // if(ans%4 != 0){
    //     sol++;
    // }

    // cout<<sol<<endl;


}