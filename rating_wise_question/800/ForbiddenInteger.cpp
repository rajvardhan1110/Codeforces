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
    int n,k,x;
 
    cin>>n>>k>>x;
 
    if(k==1 && x==1){
        cout<<"NO"<<endl;
        return;
    }
 
    if(x!=1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
 
        while(n!=0){
            cout<<1<<" ";
            n--;
        }
        cout<<endl;
        return;
    }else{
        if(n%2==0){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
 
            while(n!=0){
                cout<<2<<" ";
                n -=2;
            }
            cout<<endl;
            return;
        }else{
            if(k==2){
                cout<<"NO"<<endl;
                return;
            }else{
                cout<<"YES"<<endl;
 
                int a=n-3;
 
                cout<<1+(a/2)<<endl;
 
                cout<<3<<" ";
 
                n -= 3;
 
                while(n!=0){
                    cout<<2<<" ";
                    n -=2;
                }
                cout<<endl;
                return;
            }
        }
    }
}