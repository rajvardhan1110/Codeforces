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

    string a;
    string b;
    cin>>a;
    cin>>b;

    int count=0;
    vector<bool> ch(n,false);

    for(int i=0; i<n; i++){
        if(b[i]=='1'){
            if(a[i]=='0'){
                ch[i]=true;
                count++;
            }else{
                if((i-1 >=0 && a[i-1]=='1' && ch[i-1]==false)){
                    count++;
                    ch[i-1]=true;
                }else if((i+1 < n) && a[i+1]=='1'&& ch[i+1]==false){
                    count++;
                    ch[i+1]=true;
                }
            }
        }
    }

    cout<<count<<endl;
}