#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

bool check(ll mid, ll maxi, double avg, ll n, vector<ll> &arr){
    bool keep = true;
    ll cnt = 0;

    for(ll i = 0; i < n; i++){
        ll num = arr[i];
        if(arr[i] == maxi && keep){
            num += mid;
            keep = false;
        }

        if(num < avg / 2.0){  
            cnt++;
        }
    }

    return cnt > n / 2;
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
    ll n;
    cin >> n;

    vector<ll> arr(n);
    inputV(arr, n);

    ll maxi = *max_element(arr.begin(), arr.end());
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);

    ll l = 0;
    ll h = 2e12;  
    ll ans = -1;

    while(l <= h){
        ll mid = (l + h) / 2;
        double avg = (sum + mid) / (double)n;  

        if(check(mid, maxi, avg, n, arr)){
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}
