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

    string var;
    string khali;

    cin>>var;
    cin>>khali;

    int lv=0;
    int lk=0;

    int rv=0;
    int rk=0;

    int i=0;
    int j=0;

    while(i<var.size() && j<khali.size()){
        if(var[i]=='L'){
            while(i<var.size() && var[i]=='L'){
                lv++;
                i++;
            }

            while(j<khali.size() && khali[j]=='L'){
                lk++;
                j++;
            }


            if(lv*2 < lk || lv > lk){
                cout<<"NO"<<endl;
                return;
            }

            lv=0;
            lk=0;
        }else{
            while(i<var.size() && var[i]=='R'){
                rv++;
                i++;
            }

            while(j<khali.size() && khali[j]=='R'){
                rk++;
                j++;
            }


            if(rv*2 < rk || rv > rk){
                cout<<"NO"<<endl;
                return;
            }

            rv=0;
            rk=0;
        }
    }

    if(i==var.size() && j==khali.size()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}