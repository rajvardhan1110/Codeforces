#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<string, long long>> rounds(n);
    map<string, long long> finalScore;

    for (int i = 0; i < n; i++) {
        cin >> rounds[i].first >> rounds[i].second;
        finalScore[rounds[i].first] += rounds[i].second;
    }

 
    long long M = LLONG_MIN;
    for (auto &p : finalScore) {
        M = max(M, p.second);
    }

 
    map<string, long long> runningScore;
    for (int i = 0; i < n; i++) {
        string name = rounds[i].first;
        long long points = rounds[i].second;
        runningScore[name] += points;

        if (runningScore[name] >= M && finalScore[name] == M) {
            cout << name << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
