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

    vector<int> arr(26,0);

    int n=s.size();
    int sum=0;

    for(int i=0; i<n; i++){
        int index = s[i]-'a';
        arr[index]++;
        sum++;

        
    }

    int count=0;
    

    for(int i=0; i<26; i++){
        if(arr[i]==0){
            break;
        }

        if(arr[i]==1){
            count++;
        }
    }

    // if(count==n){
    //     cout<<"YES"<<endl;
    // }else{
    //     cout<<"NO"<<endl;

    // }

    int i=0;
    int j=n-1;

    int cheak;

    if(s[i] > s[j]){
        cheak=0;
    }else{
        cheak=j;
    }

    bool flag=true;

    while(1){
        if(i==j){
            break;
        }

        if(cheak==i){
            if(s[cheak]-1 == s[j]){
                i++;
                cheak=j;

            }else if(s[cheak]-1 == s[i+1]){
                i++;
                cheak=i;
            }else{
                flag=false;
                break;
            }
        }else{
            if(s[cheak]-1 == s[i]){
                j--;
                cheak=i;
            }else if(s[cheak]-1 == s[j-1]){
                j--;
                cheak=j;
            }else{
                flag=false;
                break;
            }
        }

        
    }

    if(count==n && flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

    }

    
}