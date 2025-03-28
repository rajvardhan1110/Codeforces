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

    int a,a0;
    int b,b0;

    cin>>a>>a0>>b>>b0;

    string A=to_string(a);
    string B=to_string(b);

    // if(a0 > b0){
    //     A += string(a0 - b0, '0');
    // }else if(b0>a0){
    //    B += string(b0 - a0, '0');
    // }




    // if (A.length() > B.length()) {
    //     cout << ">" << endl;
    // } else if (A.length() < B.length()) {
    //     cout << "<" << endl;
    // } else {
       
    //     if (A > B) {
    //         cout << ">" << endl;
    //     } else if (A < B) {
    //         cout << "<" << endl;
    //     } else {
    //         cout << "=" << endl;
    //     }
    // }

    int num1=A.length() + a0;
    int num2=B.length() + b0;

    if(num1>num2){
        cout<<">"<<endl;
    }else if(num1<num2){
        cout<<"<"<<endl;
    }else{
        // if(A>B){
        //     cout<<">"<<endl;
        // }else if(B>A){
        //     cout<<"<"<<endl;
        // }else{
        //     cout<<"="<<endl;
        // }


        if(a0>b0){
            while(a0!=b0){
                a *= 10;
                a0--;
            }

            if(a>b){
                cout<<">"<<endl;
            }else if(a<b){
                cout<<"<"<<endl;
            }else{
                cout<<"="<<endl;
            }
        }else if(a0<b0){
            while(a0!=b0){
                b *= 10;
                b0--;
            }

            if(a>b){
                cout<<">"<<endl;
            }else if(a<b){
                cout<<"<"<<endl;
            }else{
                cout<<"="<<endl;
            }

        }else{
            if(a>b){
                cout<<">"<<endl;
            }else if(a<b){
                cout<<"<"<<endl;
            }else{
                cout<<"="<<endl;
            }
        }

    }



}