#include <bits/stdc++.h>
using namespace std;

void inputV (vector <int> &v, int size) {
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

int fact(long long n){
    if(n==1){
        return 1;
    }

    return n*fact(n-1);
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
    long long n,d;
    cin>>n>>d;

    bool a3=false,a5=false,a7=false,a9=false;

    //for 3
    if(n>=3){
        a3=true;
    }else{
        long long num=fact(n);
        if((num*d)%3==0){
            a3=true;
        }
    }

    //for5 5
    if(d==5 || d==0){
        a5=true;
    }

    //for 7
    if(n>=3 || d==7){
        a7=true;
    }

    //for 9

    if(n>=9){
        a9=true;
    }else{
        long long num=fact(n);
        if((num*d)%9==0){
            a9=true;
        }

    }

    //print

    cout<<"1"<<" ";

    if(a3==true){
        cout<<"3"<<" ";
    }

    if(a5==true){
        cout<<"5"<<" ";
    }

    if(a7==true){
        cout<<"7"<<" ";
    }

    if(a9==true){
        cout<<"9"<<" ";
    }

    cout<<endl;



}