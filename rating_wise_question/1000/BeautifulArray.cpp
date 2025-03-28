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
    int n,k,b,s;
    cin>>n>>k>>b>>s;

    vector<int> arr(n,0);

    int min_sum = k * b;
    int max_sum = ((k * (b + 1)) - 1) + (k - 1) * (n - 1);

    if(s < min_sum || s>max_sum){
        cout<<-1<<endl;
        return;
    }

    arr[n-1] = k*b;

    int rem=s-(k*b);

    for(int i=0; i<n-1; i++){
        if(rem==0){
            break;
        }

        int a=(k-1) - arr[i];
        if(rem < a){
            arr[i] += rem;
            rem=0;
            break;
        }else{
            arr[i] += a;
            rem -= a;
        }
    }

    if(rem!=0){
        arr[n-1] += rem;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}