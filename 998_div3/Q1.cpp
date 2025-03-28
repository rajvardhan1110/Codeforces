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

int cheak(int a1,int a2,int a3,int a4,int a5){
     int count = 0;
    if (a3 == a1 + a2) count++; 
    if (a4 == a2 + a3) count++;
    if (a5 == a3 + a4) count++; 
    return count;
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
    int a1,a2,a4,a5;
    cin>>a1>>a2>>a4>>a5;

    vector<int> arr(3);
    arr[0]=a1+a2;
    arr[1]=a4-a2;
    arr[2]=a5-a4;

    int count=0;

    for(int i=0; i<3; i++){
        count = max(count,cheak(a1,a2,arr[i],a4,a5));
    }

    cout<<count<<endl;
}