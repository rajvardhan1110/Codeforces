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

    vector<ll> arr(n);
    inputV(arr, n);

    ll cnt0 = 0, cnt5 = 0;
    set<ll> s;

    for (ll i = 0; i < n; i++)
    {
        ll last = arr[i] % 10;
        if (last == 0)
            cnt0++;
        if (last == 5)
            cnt5++;
        s.insert(arr[i]);
    }

    if (cnt0 == n) {
    if (s.size() == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return;
}


    if (cnt5 == n)
    {
        if (s.size() == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        return;
    }

    if (cnt0 + cnt5 == n)
    {
        if (s.size() == 2)
        {
            vector<ll> nums(s.begin(), s.end());
            ll a = nums[0], b = nums[1];

            if ((a % 10 == 5 && b % 10 == 0 && a + 5 == b) ||
                (b % 10 == 5 && a % 10 == 0 && b + 5 == a))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            return;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }

    bool ch1 = true;
    bool ch2 = true;

    vector<ll> even1;
    vector<ll> odd3;

    vector<ll> even3;
    vector<ll> odd1;

    int groupA = 0, groupB = 0;

    for (ll x : arr)
    {
        ll unit = x % 10;
        if (unit == 0 || unit == 5)
            continue;

        ll second_last;
        if (x < 10)
        {
            second_last = 0;
        }
        else
        {
            second_last = (x / 10) % 10;
        }

        bool even = (second_last % 2 == 0);
        bool odd = !even;

        if (
            ((unit == 1 || unit == 2 || unit == 4 || unit == 8) && even) ||
            ((unit == 7 || unit == 3 || unit == 6 || unit == 9) && odd))
        {
            groupA++;
        }
        else
        {
            groupB++;
        }
    }

    if (groupA == n || groupB == n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}