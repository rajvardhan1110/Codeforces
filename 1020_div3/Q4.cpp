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

    int n1,n2;
    cin>>n1>>n2;
    vector<int> up(n1);
    vector<int> down(n2);
    inputV(up,n1);
    inputV(down,n2);

    //for 0 case
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(up[i] >= down[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }

    if(j==n2){
        cout<<0<<endl;
        return;
    }

    //from left

    bool iup = false;
    int idxup = -1;

    i=0;
    j=0;

    while(i<n1 && j<n2){
        if(up[i] == down[j]){
            iup=false;
            i++;
            j++;
        }else{
            if(iup == false){
                iup = true;
                idxup = i;
                i++;
            }
        }
    }

    int ansleft = down[j];

    //for next left
    int y = idxup;
    int z = +1;

    while(y < n1 && z<n2){
        if(up[y] >= down[z]){
            y++;
            z++;
        }else{
            y++;
        }
    }

    bool lefty = false;

    if(z==n2){
        lefty = true;
    }


    //for right

    bool idown = false;
    int idxdown = -1;

    i=n1-1;
    j=n2-1;

    while(i>=0 && j>=0){
        if(up[i] == down[j]){
            idown=false;
            i--;
            j--;
        }else{
            if(idown == false){
                idown = true;
                idxdown = i;
                i--;
            }
        }
    }

    int ansright = down[j];

    //for prev right

    y = idxdown;
    z = j-1;

    while(y >= 0 && z >= 0){
        if(up[y] >= down[z]){
            y--;
            z--;
        }else{
            y--;
        }
    }

    bool righty = false;

    if(z==-1){
        righty = true;
    }

    if(lefty || righty){
        cout<<min(ansleft,ansright)<<endl;
    }else{
        cout<<-1<<endl;
    }



}