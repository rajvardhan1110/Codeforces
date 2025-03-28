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
    // Add your code here'
    int n1,n2;
    cin>>n1>>n2;

    string s1;
    string s2;

    cin>>s1;
    cin>>s2;
    int ans=0;

    while(1){
        if(s1.length()<s2.length()){
            s1 += s1;
            ans++;
            continue;

        }else{
            if (s1.find(s2) != std::string::npos) {
                cout<<ans<<endl;
                return;
             } else {
        

                if(ans>=5){
                 cout<<-1<<endl;
                 return;
                 }
            }
        }

        s1 += s1;
        ans++;
    }

}