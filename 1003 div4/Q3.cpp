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
        cout << v[i]<<" ";
    }

    cout<<endl;
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

    int n,m;

    cin>>n>>m;

    vector<int> arr(n);
    vector<int> Mnum(1);

    inputV(arr,n);
    inputV(Mnum,1);

    // printV(arr,n);
    // printV(Mnum,1);

    if(n==1){
        cout<<"YES"<<endl;
        return;
    }

    // arr[0]=Mnum[0]-arr[0];

    if(Mnum[0]-arr[0] < arr[0]){
        arr[0]=Mnum[0]-arr[0];
    }


    for(int i=1; i<n; i++){
    //    if(Mnum[0]-arr[i] >= arr[i-1]){
    //         arr[i]=Mnum[0]-arr[i];
    //    }

    int a=arr[i];
    int b=Mnum[0]-arr[i];

    int mini;
    int maxi;

        if(a<b){
            mini=a;
            maxi=b;
        }else{
            mini=b;
            maxi=a;
        }

        if(maxi>=arr[i-1]){
            arr[i]=maxi;
        }

        if(mini>=arr[i-1]){
            arr[i]=mini;
        }

        
    }

    // printV(arr,n);

    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;





}