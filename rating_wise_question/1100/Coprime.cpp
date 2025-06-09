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

    vector<int> arr(n);
    inputV(arr,n);

    // int G = 0;

    // int index = -1;

    // for(int i=n-1; i>=0; i--){
    //     G = __gcd(G,arr[i]);
        
    //     if(G==1){
    //         index = i;
    //         break;
    //     }
    // }

    // if(G != 1){
    //     cout<<-1<<endl;
    //     return;
    // }

    // int index2 = -1;

    // for(int i=n-1; i>=index; i--){
    //     if((__gcd(arr[index],arr[i])) == 1){
    //         index2 = i;
    //         break;
    //     }
    // }

    // cout<<__gcd(2,15)<<endl;

    // cout<<index<<" "<<index2<<endl;

    // cout<<index+1+index2+1<<endl;

    // map<int,int> mp;

    // for(int i=0; i<n; i++){
    //     mp[arr[i]] = i;
    // }

    // vector<int> a;

    // for(auto i:mp){
    //     a.push_back(i.second);
    //     // cout<<i.first<<" "<<i.second<<endl;
    // }

    // // cout<<endl;

    // sort(a.begin(),a.end());

    // // cout<<a.size()<<endl<<endl;;

    // // for(int i=0; i<a.size(); i++){
    // //     cout<a[i]<<" ";
    // // }

    // // cout<<endl;

    // for(int i=a.size()-1; i>=0; i--){
    //     for(int j=i; j>=0; j--){
    //         if((__gcd(arr[a[i]],arr[a[j]])) == 1){

    //             cout<<a[i]+1+a[j]+1<<endl;
    //             return;
    //         }
    //     }
    // }

    // cout<<-1<<endl;

    // // cout<<endl<<endl;

    map<int,int> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]] = i;
    }

    vector<int> a;

    for(auto i:mp){
        a.push_back(i.second);
    }

    sort(a.begin(),a.end());
    

    int si = a.size();

    // for(auto i:a){
    //     cout<<i<<" ";
    // }

    // cout<<endl;

    int maxi = INT_MIN;
    int ans1= -1;
    int ans2= -1;

    for(int i=si-1; i>=0; i--){
        int num1 = arr[a[i]];

        for(int j=i; j>=0; j--){
            int num2 = arr[a[j]];

            if(__gcd(num1,num2) == 1){
                // cout<<num1<<" "<<num2<<endl;
                // cout<<a[i]+a[j]+2<<endl;
                // return;

                if(maxi < a[i]+a[j]+2){
                    ans1 = a[i];
                    ans2 =a[j];

                    maxi = a[i]+a[j]+2;
                }
            }
        }
    }

    if(ans1 == -1 && ans2 == -1){
        cout<<-1<<endl;
    }else{
        cout<<ans1+ans2+2<<endl;
    }

    // cout<<-1<<endl;
}