#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else {
        return (res * res) % MOD;
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n;
    cin>>n;

    vector<ll> arr(n);



    inputV(arr,n);

    // if(n == 3){
    //     if(arr[0] <= arr[1] && arr[1] <= arr[2]){
    //         cout<<0<<endl;
    //         return;
    //     }

    //     if(arr[1] <= arr[0] && arr[1] <= arr[2]){
    //         cout<<1<<endl;
    //         cout<<1<<" "<<2<<" "<<3<<endl;
    //         return;
    //     }

    //     if(arr[1] >= arr[0] && arr[1] >= arr[2]){
    //         cout<<2<<endl;
    //         cout<<1<<" "<<3<<" "<<2<<endl;
    //         cout<<3<<" "<<2<<" "<<1<<endl;
    //         return;
            
    //     }

    //     if(arr[0] > arr[1] && arr[1] > arr[2]){
    //         cout<<-1<<endl;
    //         return;
    //     }

    // }

    // cout<<n<<endl;


    // if(arr[0] >= arr[1]){
    //     cout<<n<<" "<<1<<" "<<2<<endl;
    //     cout<<n-1<<" "<<1<<" "<<2<<endl;
    // }else{
    //     cout<<n<<" "<<2<<" "<<1<<endl;
    //     cout<<n-1<<" "<<2<<" "<<1<<endl;
    // }
    

    // for(ll i = 0; i < n-2; i++){
       
    //     cout<<i+1<<" "<<n<<" "<<n-1<<endl;
    // }


    if(arr[n-2] <= arr[n-1]){

        if(arr[n-1] < 0){
            vector<ll> dummy = arr;

            sort(dummy.begin(),dummy.end());

            if(dummy == arr){
                cout<<0<<endl;
            }else{
                cout<<-1<<endl;
            }

            return;
        }

        cout<<n-2<<endl;

        for(ll i = 0; i < n-2; i++){
       
            cout<<i+1<<" "<<n-1<<" "<<n<<endl;
        }

    }else{
        cout<<-1<<endl;
    }
}