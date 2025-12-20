#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else {
        return (res * res) % MOD;
    }
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
    vector<ll> nums;
    inputV(nums, n);

    vector<ll> oddNums, evenNums;

    for (ll i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) evenNums.push_back(nums[i]);
        else oddNums.push_back(nums[i]);
    }

    if (evenNums.empty()) {
        ll maxVal = *max_element(nums.begin(), nums.end());
        for (ll i = 0; i < n; i++) {
            if (i % 2 == 0) cout << maxVal << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
        return;
    }

    if (oddNums.empty()) {
        for (ll i = 0; i < n; i++) cout << 0 << " ";
        cout << "\n";
        return;
    }

    bool evenOddFlag = (oddNums.size() % 2 == 0);

    sort(oddNums.rbegin(), oddNums.rend());
    sort(evenNums.rbegin(), evenNums.rend());

    vector<ll> result;
    result.push_back(oddNums[0]);
    for (ll x : evenNums) result.push_back(x);

    ll runningSum = 0;
    ll count = 1;
    ll printed = 0;

    for (ll x : result) {
        runningSum += x;
        cout << runningSum << " ";
        count++;
        printed++;
    }

    ll totalSum = runningSum;
    ll smallestEven = *min_element(evenNums.begin(), evenNums.end());
    bool toggle = true;

    while (count < n) {
        if (toggle) {
            cout << totalSum - smallestEven << " ";
            toggle = false;
        } else {
            cout << totalSum << " ";
            toggle = true;
        }
        printed++;
        count++;
    }

    if (printed == n) {
        cout << "\n";
        return;
    }

    if (evenOddFlag) cout << 0 << "\n";
    else cout << (toggle ? totalSum - smallestEven : totalSum) << "\n";
}
