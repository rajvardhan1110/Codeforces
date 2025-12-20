#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n=0): n(n), f(n+1,0) {}
    void add(int i, int delta){ for(; i<=n; i += i & -i) f[i] += delta; }
    int sum(int i){ int r = 0; for(; i>0; i -= i & -i) r += f[i]; return r; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n; cin >> n;
        vector<pair<ll,ll>> arr(n);
        vector<ll> vals;
        for(int i=0;i<n;i++){
            cin >> arr[i].first >> arr[i].second;
            vals.push_back(arr[i].second);
        }

        // coordinate compress second values
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = (int)vals.size();
        Fenwick bit(m);

        // initial frequency: add all elements
        for(int i=0;i<n;i++){
            int pos = int(lower_bound(vals.begin(), vals.end(), arr[i].second) - vals.begin()) + 1;
            bit.add(pos, 1);
        }

        // sort by first (as in your original logic)
        sort(arr.begin(), arr.end());

        long long ans = 0;
        for(int i=0;i<n;i++){
            int pos = int(lower_bound(vals.begin(), vals.end(), arr[i].second) - vals.begin()) + 1;
            // remove this element (equivalent to s.erase(find(...)))
            bit.add(pos, -1);

            // count of remaining elements <= arr[i].second
            ans += bit.sum(pos);
        }

        cout << ans << '\n';
    }
    return 0;
}
