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
    string s;
    cin>>s;

    int n=s.size();

    int cnt=0;
    int sum=0;

    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            sum++;
        }else{
            cnt = max(cnt,sum);
            sum=0;
        }
    }

    cnt = max(cnt,sum);

    if(cnt == n){
        cout<< n*n <<endl;
        return;
    }

    if(cnt == 0){
        cout<<0<<endl;
        return;
    }

    int i=0;
    int j=n-1;

    int count=0;

    while(i<n && s[i]=='1'){
        count++;
        i++;
    }

    while(j>=0 && s[j]=='1'){
        count++;
        j--;
    }

    cnt = max(cnt,count);

    int k=cnt;

    int ans=0;

    while(k){
        int a = cnt - k + 1;
        int b=k*a;
        ans = max(ans,b);
        k--;
    }

    cout<<ans<<endl;

}