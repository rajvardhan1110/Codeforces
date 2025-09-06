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

    ll n;
    cin >> n;

    vector<ll> arr(n);
    inputV(arr, n);

    // vector<ll> pre(n);
    // vector<ll> suff(n);

    // stack<pair<ll,ll>> st1;

    // for(ll i =0; i<n; i++){
    //     while(!st1.empty() && st1.top().first <= arr[i]){
    //         st1.pop();
    //     }

    //     if(st1.empty()){
    //         pre[i] = -1;
    //     }else{
    //         pre[i] = st1.top().second;
    //     }

    //     st1.push({arr[i],i});
    // }

    // stack<pair<ll,ll>> st2;

    // for(ll i =n-1; i>=0; i--){
    //     while(!st2.empty() && st2.top().first <= arr[i]){
    //         st2.pop();
    //     }

    //     if(st2.empty()){
    //         suff[i] = n;
    //     }else{
    //         suff[i] = st2.top().second;
    //     }

    //     st2.push({arr[i],i});
    // }

    // vector<pair<ll,ll>> grp(n);

    // for(ll i = 0; i<n; i++){
    //     ll take = (i-pre[i]) + (suff[i] - i) - 1;
    //     grp[i] = {arr[i],take};
    // }

    // for(int i=0; i<n; i++){
    //     cout<<grp[i].first<<" "<<grp[i].second<<endl;
    // }

    // sort(grp.begin(),grp.end());

    // for(int i=0; i<n; i++){
    //     cout<<grp[i].first<<" "<<grp[i].second<<endl;
    // }

    sort(arr.begin(), arr.end());

    ll x;
    cin >> x;

    // cout<<x<<endl;

    while (x--)
    {
        ll num;
        cin >> num;

        // cout<<num<<endl;

        auto it = upper_bound(arr.begin(), arr.end(), num);

        if (it != arr.end())
        {
            if (it != arr.begin())
            {
                auto prev = it - 1;
                cout << (prev - arr.begin()) + 1 << endl; 
            }
            else
            {
                cout << 0 << endl; 
            }
        }
        else
        {
            cout << n << endl; 
        }
    }
}