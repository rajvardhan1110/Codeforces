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

    string s;
    cin >> s;

    map<char, ll> mp;

    for (auto i : s)
    {
        mp[i]++;
    }

    ll minNS = min(mp['N'], mp['S']);
    ll minEW = min(mp['E'], mp['W']);

    if ((mp['N'] - minNS) % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    else if ((mp['S'] - minNS) % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    else if ((mp['E'] - minEW) % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    else if ((mp['W'] - minEW) % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }

    ll RN = minNS;
    ll RNN = (mp['N'] - minNS) / 2;
    ll HNN = (mp['N'] - minNS) / 2;

    ll RS = minNS;
    ll RSS = (mp['S'] - minNS) / 2;
    ll HSS = (mp['S'] - minNS) / 2;

    if (mp['N'] - mp['S'] == 0)
    {
         RN = minNS - 1;
         RNN = (mp['N'] - minNS) / 2;
         HNN = (mp['N'] - minNS) / 2 + 1;

         RS = minNS - 1;
         RSS = (mp['S'] - minNS) / 2;
         HSS = (mp['S'] - minNS) / 2 + 1;
    }

    ll HE = minEW;
    ll HEE = (mp['E'] - minEW) / 2;
    ll REE = (mp['E'] - minEW) / 2;

    ll HW = minEW;
    ll HWW = (mp['W'] - minEW) / 2;
    ll RWW = (mp['W'] - minEW) / 2;

    if (mp['E'] - mp['W'] == 0)
    {
        HE = minEW - 1;
        HEE = (mp['E'] - minEW) / 2;
        REE = (mp['E'] - minEW) / 2 + 1;

        HW = minEW - 1;
        HWW = (mp['W'] - minEW) / 2;
        RWW = (mp['W'] - minEW) / 2 + 1;
    }

    string ans = "";

    for (auto i : s)
    {
        if (i == 'N')
        {
            if (RN > 0)
            {
                RN--;
                ans += 'R';
            }
            else if (RNN > 0)
            {
                RNN--;
                ans += 'R';
            }
            else
            {
                HNN--;
                ans += 'H';
            }
        }

        if (i == 'S')
        {
            if (RS > 0)
            {
                RS--;
                ans += 'R';
            }
            else if (RSS > 0)
            {
                RSS--;
                ans += 'R';
            }
            else
            {
                HSS--;
                ans += 'H';
            }
        }

        if (i == 'E')
        {
            if (HE > 0)
            {
                HE--;
                ans += 'H';
            }
            else if (HEE > 0)
            {
                HEE--;
                ans += 'H';
            }
            else
            {
                REE--;
                ans += 'R';
            }
        }

        if (i == 'W')
        {
            if (HW > 0)
            {
                HW--;
                ans += 'H';
            }
            else if (HWW > 0)
            {
                HWW--;
                ans += 'H';
            }
            else
            {
                RWW--;
                ans += 'R';
            }
        }
    }

    bool r = false;
    bool h = false;

    for (auto i : ans)
    {
        if (i == 'R')
            r = true;
        if (i == 'H')
            h = true;
    }

    if (r && h)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}