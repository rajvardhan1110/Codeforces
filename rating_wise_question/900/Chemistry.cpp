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

    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    // vector<int> odd;
    // vector<int> even;

    map<char,int> mp;

    for(int i=0; i<n; i++){
        mp[s[i]]++;
    }

    // vector<int> num;
    int odd=0;

    for(auto i:mp){
        // num.push_back(i.second);
        if(i.second % 2 != 0){
            odd++;
        }
    }

    

    // for(int i=0; i<num.size(); i++){
    //     if(num[i]%2==0){
    //         // even.push_back(num[i]);
    //     }else{
    //         // odd.push_back(num[i]);
    //     }
    // }

    // sort(odd.begin(),odd.end());
    // sort(even.begin(),even.end());

    // for(int i=0; i<odd.size(); i++){
    //     if(k<=odd[i]){
    //         odd[i] -= k;
    //         k=0;
    //     }else if(k>odd[i]){
    //          k-= odd[i];
    //          odd[i]=0;
    //     }
    // }

    // for(int i=0; i<even.size(); i++){
    //     if(k<=even[i]){
    //         even[i] -= k;
    //         k=0;
    //     }else if(k>even[i]){
    //          k-= even[i];
    //          even[i]=0;
    //     }
    // }

    // int count=0;

    //  for(int i=0; i<odd.size(); i++){
    //     if(odd[i]%2!=0){
    //         count++;
    //     }
    // }

    // for(int i=0; i<even.size(); i++){
    //     if(even[i]%2!=0){
    //         count++;
    //     }
    // }

    

    if(k<odd-1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }

}