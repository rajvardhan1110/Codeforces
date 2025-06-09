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

    vector<int> ar1(n);
    vector<int> ar2(n);
    inputV(ar1,n);
    inputV(ar2,n);

    // int index1 = -1;
    // int index2 = -1;

    // int maxi = INT_MIN;

    // int l=0;
    // int r=1;

    // while(r<n){
    //     if(ar2[r] < ar2[r-1]){
    //         vector<int> sr(ar1.begin()+l,ar1.begin()+r);
    //         vector<int> check(ar2.begin()+l,ar2.begin()+r);

    //         sort(sr.begin(),sr.end());

    //         if(sr == check){
    //             int a = r-l;

    //             if(a>=maxi){
    //                 index1 = l+1;
    //                 index2 = r;

    //                 maxi = a;
    //             }
    //         }
    //     }else{
    //         l = r;
    //     }

    //     r++;
    // }

    // cout<<index1<<" "<<index2<<endl;

    int l=0;
    int r=n-1;

    while(ar1[l]==ar2[l]){
        l++;
    }

    while(ar1[r]==ar2[r]){
        r--;
    }

    bool flag = false;

    while(l>0){
        if(ar2[l]>=ar2[l-1]){
            l--;
            flag=true;
        }else{
            
            break;
        }
    }

    while(r<n-1){
        if(ar2[r]<=ar2[r+1]){
            r++;
        }else{

            break;
        }
    }





    cout<<l+1<<" "<<r+1<<endl;
}