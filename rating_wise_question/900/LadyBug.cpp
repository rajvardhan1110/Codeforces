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

    // vector<int> a(n);
    // vector<int> b(n);

    // inputV(a,n);
    // inputV(b,n);

    string a;
    string b;

    cin>>a;
    cin>>b;

    // int count=0;

    // for(int i=0; i<n; i++){
    //     if(a[i]=='1'){
    //         count++;
    //     }

    //     if(b[i]=='1'){
    //         count++;
    //     }
    // }

    // if(count>n){
    //     cout<<"NO"<<endl;
    //     return;
    // }

    // if(count%2==0){
    //     cout<<"YES"<<endl;
    // }else{
    //     cout<<"NO"<<endl;
    // }


    int upodd=0;
    int upeven=0;

    int downodd=0;
    int downeven=0;

    for(int i=0; i<n; i++){
        if(i%2==0){
            if(a[i]=='1'){
                upeven++;
            }

            if(b[i]=='0'){
                downeven++;
            }
        }else{
            if(a[i]=='1'){
                upodd++;
            }

            if(b[i]=='0'){
                downodd++;
            }
        }

        // cout<<upeven<<" "<<upodd<<" "<<downeven<<" "<<downodd<<endl<<endl;
    }


    if(downodd >= upeven && downeven >= upodd){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}