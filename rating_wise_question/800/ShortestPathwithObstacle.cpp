#include <bits/stdc++.h>
using namespace std;

void inputV (vector <long long> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(vector<int> &v, int size){
    for(int i=0; i<size; i++){
        cout<<v[i];
    }
}

void createsieve(vector<bool> &prime, int n){
    // Declare prime vector in solve function with size n+1 and all values are true
    prime[0] = prime[1] = false;
    for(int i=2; i<n; i++){
        if(prime[i]){
            for(int j=2*i; j<n; j+=i){
                prime[j] = false;
            }
        }
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    // Implementation here
    int a,b,c,d,e,f;

    cin>>a>>b>>c>>d>>e>>f;

    int x=abs(c-a);
    int y=abs(d-b);

    if(((a==c)&&(c==e)) && ((b<f && d>f)||(b>f && d<f))){
        cout<<x+y+2<<endl;
    }else if(((b==d)&&(d==f)) && ((a<e && c>e)||(a>e && c<e))){
        cout<<x+y+2<<endl;
    }else{
        cout<<x+y<<endl;
        
    }

   
    
}