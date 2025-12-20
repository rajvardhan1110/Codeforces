#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
constexpr ll MOD = 1000000007;

void inputV(vector<ll> &v, int n)
{
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

void createSieve(vector<bool> &prime, int n)
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

bool isPowerOfTwo(ll x)
{
    return x > 0 && (x & (x - 1)) == 0;
}

ll binExp(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binExp(a, b / 2);
    if (b & 1)
        return (a * ((res * res) % MOD)) % MOD;
    return (res * res) % MOD;
}

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

void solve()
{
    // int n;
    // ll pos;
    // cin >> n >> pos;

    // struct cas {
    //     ll l, r, j;
    // };

    // vector<cas> c(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> c[i].l >> c[i].r >> c[i].j;
    // }

    // sort(all(c), [](const cas &a, const cas &b) {
    //     return a.l < b.l;
    // });

    // ll curr = pos;
    // int idx = 0;
    // priority_queue<ll> pq;

    // while (true) {
    //     while (idx < n && c[idx].l <= curr) {
    //         if (c[idx].r >= curr) {
    //             pq.push(c[idx].j);
    //         }
    //         idx++;
    //     }

    //             while (!pq.empty() && pq.top() <= curr) {
    //                 pq.pop();
    //             }

    //     if (pq.empty()) break;

    //             curr = pq.top();
    //             pq.pop();
    // }

    // cout << curr << '\n';

    ll n, ans;
    cin >> n >> ans;

    vector<pair<pair<ll, ll>, ll>> arr;

    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        arr.push_back({{a, b}, c});
    }

    sort(arr.begin(), arr.end());

    for(ll i = 0;i<n; i++){
        if(arr[i].first.first <= ans){
            if(arr[i].second > ans){
                ans = arr[i].second;
            }
        }
    }

    cout<<ans<<endl;
}
