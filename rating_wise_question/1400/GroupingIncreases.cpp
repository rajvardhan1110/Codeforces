#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, ll size)
{
    v.resize(size);
    for (ll i = 0; i < size; i++)
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

void createsieve(vector<bool> &prime, ll n)
{
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j < n; j += i)
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

ll binExpRecur(ll arr, ll b)
{
    if (b == 0)
        return 1;
    ll res = binExpRecur(arr, b / 2);
    if (b & 1)
    {
        return (arr * ((res * res) % MOD)) % MOD;
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

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

void solve()
{
    // Rajvardhan Patil

    // ll n;
    // cin >> n;

    // vector<ll> arr(n);
    // inputV(arr, n);

    // if (n == 1)
    // {
    //     cout << 0 << endl;
    //     return;
    // }

    // vector<ll> dummy = arr;
    // sort(dummy.begin(), dummy.end());

    // reverse(arr.begin(), arr.end());
    // // printV(arr);

    // // bool flag = false;
    // ll prev = -1;

    // vector<ll> extra;
    // // printV(arr);

    // vector<bool> result(n, false);
    // stack<ll> st;
    // for (ll i = n - 1; i >= 0; --i)
    // {

    //     while (!st.empty() && st.top() < arr[i])
    //     {
    //         st.pop();
    //     }

    //     if (!st.empty())
    //     {
    //         result[i] = true;
    //     }

    //     st.push(arr[i]);
    // }

    // for (ll i = 0; i < n; i++)
    // {
    //     if (prev != -1)
    //     {
    //         if (arr[i] >= prev)
    //         {
    //             prev = arr[i];
    //         }
    //         else
    //         {
    //             extra.push_back(arr[i]);
    //         }
    //     }
    //     else
    //     {
    //         if (result[i] == 1)
    //         {
    //             prev = arr[i];
    //         }
    //         else
    //         {
    //             extra.push_back(arr[i]);
    //         }
    //     }
    // }

    // // printV(extra);
    // reverse(extra.begin(), extra.end());
    // reverse(arr.begin(), arr.end());
    // // printV(extra);

    // ll ans = 0;

    // for (ll i = 1; i < extra.size(); i++)
    // {
    //     // cout<<ans<<endl;
    //     if (extra[i] > extra[i - 1])
    //     {
    //         ans++;
    //     }
    //     // cout<<ans<<endl;
    // }

    // if (dummy == arr)
    // {
    //     if (n & 1)
    //     {
    //         if (n == 3)
    //         {
    //             ans = min(ans, 1LL);
    //         }
    //         ans = min(ans, n / 2 + 1);
    //     }
    //     else
    //     {
    //         if (n == 2)
    //         {
    //             cout << 0 << endl;
    //             return;
    //         }
    //         ans = min(ans, n / 2);
    //     }
    // }

    // cout << ans << endl;

    ll n;
    cin >> n;

    vector<ll> arr(n);
    inputV(arr, n);
    ll penalty = 0;

    ll x = INT_MAX, y = INT_MAX; 
    for (ll i = 0; i < n; ++i) {
        ll cur = arr[i];

        
        if (x > y) swap(x, y);

        if (cur <= x) {
            x = cur; 
        } else if (cur <= y) {
            y = cur; 
        } else {
           
            penalty++;
            x = cur;
        }
    }
    cout<<penalty<<endl;
}