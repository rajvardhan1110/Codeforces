#include <bits/stdc++.h>
using namespace std;
#define int long long

void inputV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i];
    }
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    // Add your code here
     int n,a,b;
    cin>>n>>a>>b;

    map<int,set<int>> adj1;
    map<int,set<int>> adj2;

    for(int i=0; i<a; i++){
        int a,b;
        cin>>a>>b;

        adj1[a].insert(b);
        adj1[b].insert(a);
    }

    for(int i=0; i<b; i++){
        int a,b;
        cin>>a>>b;

        adj2[a].insert(b);
        adj2[b].insert(a);
    }

    int count=0;

    for (auto& i : adj1) { 
    for (auto it = i.second.begin(); it != i.second.end(); ) {
        
        if (adj2[i.first].find(*it) == adj2[i.first].end()) {
            adj1[*it].erase(i.first);
            it = i.second.erase(it); 
            count++;
        } else {
            ++it; 
        }
    }
}

    for (auto& i : adj2) { 
    for (auto it = i.second.begin(); it != i.second.end(); ) {
        
        if (adj1[i.first].find(*it) == adj1[i.first].end()) {
            adj1[*it].insert(i.first);
            adj1[i.first].insert(*it);
            count++;
        } else {
            ++it; 
        }
    }
}

cout<<count<<endl;


}