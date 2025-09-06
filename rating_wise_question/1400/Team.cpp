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

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

void solve()
{
    // Rajvardhan Patil

    ll z, o;
    cin >> z >> o;

    if (z > o + 1)
    {
        cout << -1 << endl;
        return;
    }

    if (2 * z < o - 2)
    {
        cout << -1 << endl;
        return;
    }

    string ans = "";

    while (o > z)
    {
        ans += "11";
        ans += '0';

        o -= 2;
        z -= 1;

        if (z == 0)
        {
            break;
        }
    }

    while (1)
    {

        if (o >= z)
        {
            if (o > 0)
            {
                ans += '1';
                o -= 1;
            }

            if (z > 0)
            {
                ans += '0';
                z -= 1;
            }
        }else{

            if (z > 0)
            {
                ans += '0';
                z -= 1;
            }

            if (o > 0)
            {
                ans += '1';
                o -= 1;
            }

            
        }

        if (o == 0 && z == 0)
        {
            break;
        }
    }

    cout << ans << endl;
}