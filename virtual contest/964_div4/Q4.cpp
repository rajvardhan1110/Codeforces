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
    string fin;

    cin>>s;
    cin>>fin;

    int i=0;
    int j=0;

    if(s.size() < fin.size()){
        cout<<"NO"<<endl;
    }

    while(j<s.size() && i<fin.size()){
        if(s[j]==fin[i]){
            i++;
            j++;
            continue;
        }


        while( j<s.size() && s[j]!=fin[i]){
           
            if(s[j]=='?' || s[j]==fin[i]){
                s[j]=fin[i];
                break;
            }

            j++;
        }

        if(s[j]==fin[i]){
            i++;
            j++;
        }

        if(j==s.size() && i<fin.size()){
            cout<<"NO"<<endl;
            return;
        }


    }

    if(j==s.size() && i<fin.size()){
        cout<<"NO"<<endl;
        return;
    }

    for(int y=0; y<s.size(); y++){
        if(s[y]=='?'){
            s[y]='z';
        }
    }

    cout<<"YES"<<endl;

    for(int y=0; y<s.size(); y++){
        cout<<s[y]<<"";
    }

    cout<<endl;
}