#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, int size)
{
    v.resize(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v)
{
    for (ll val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, int n)
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

bool PowOfTwo(ll n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1)
    {
        return (a * ((res * res) % MOD)) % MOD;
    }
    else
    {
        return (res * res) % MOD;
    }
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
    // Rajvardhan Patil

    ll n;
    cin >> n;

    ll nn = n;

    vector<pair<ll, ll>> arr;

    for (ll i = 0; i < n; i++)
    {
        ll m;
        cin >> m;

        ll a;
        cin >> a;

        ll need = a + 1;

        for (ll j = 1; j < m; j++)
        {
            ll b;
            cin >> b;

            need = max(need, b - j + 1);
        }

        arr.push_back({need, m});
    }

    sort(arr.begin(), arr.end(), [](pair<ll, ll> &a, pair<ll, ll> &b)
         {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first; });

    // ll ans = arr[0].first;

    // ll num = arr[0].second;
    // ll pow = arr[0].first + arr[0].second;

    // for(ll i =0; i<n; i++){
    //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
    // }

    // for (ll i = 1; i < n; i++)
    // {
    //     if (pow >= arr[i].first)
    //     {
    //         pow += arr[i].second;
    //         num += arr[i].second;
    //     }
    //     else
    //     {
    //         ans = arr[i].first;
    //         pow = arr[i].first + arr[i].second + num;
    //         num += arr[i].second;
    //     }
    // }

    ll ans = 0;
    ll curr_power = 0;

    for (auto [need, cnt] : arr) {
        ans = max(ans, need - curr_power);
        curr_power += cnt;
    }

    cout << ans << endl;
}