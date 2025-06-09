#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
// const int INF = 1e18, MOD = 1e9 + 7;

template<typename T> void inputV(vector<T>& vec, int size) { for (int i = 0; i < size; ++i) cin >> vec[i]; }
template<typename T> void printV(const vector<T>& vec) { for (auto val : vec) cout << val << " "; cout << "\n"; }
template<typename T> T sumV(const vector<T>& vec) { return accumulate(all(vec), (T)0); }
template<typename T> T maxV(const vector<T>& vec) { return *max_element(all(vec)); }
template<typename T> T minV(const vector<T>& vec) { return vec.empty() ? numeric_limits<T>::max() : *min_element(all(vec)); }
int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool isPrime(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
bool powerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
bool even(int n) { return n % 2 == 0; }
bool odd(int n) { return n % 2 != 0; }
template<typename T> T modExp(T base, T exp, T mod) { T res = 1; while (exp) { if (exp & 1) res = res * base % mod; base = base * base % mod; exp >>= 1; } return res; }
const int MAXN = 1e6, MOD = 1e9 + 7; int fac[MAXN + 1], inv[MAXN + 1];  
int exp(int x, int n, int m) { x %= m; int res = 1; while (n) { if (n & 1) res = res * x % m; x = x * x % m; n /= 2; } return res; }  
void factorial() { fac[0] = 1; for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD; }  
void inverses() { inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD); for (int i = MAXN; i; i--) inv[i - 1] = inv[i] * i % MOD; }  
int ncr(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }

void solve() {


    int n;
    cin >> n;
    
    vector <int> v(n);
    inputV(v, n);
    
    if (n == 2) {
        if (v[0] == v[1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    int num = minV(v);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == num) {
            cnt++;
        }
    }

    if (cnt > 1) {
        cout << "YES\n";
        return;
    }

    vector <int> divi;

    for (int i = 0; i < n; i++) {
        if (v[i] % num == 0 && v[i] != num) {
            divi.push_back(v[i]);
        }
    }

    int gc = 0;

    for (int i = 0; i < divi.size(); i++) {
        gc = gcd(gc, divi[i]);
    }

    if (gc == num) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }






}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t ;
    while (t--) solve();
    return 0;
}