#include<iostream>
using namespace std;
#define int long long
 
 
bool check (int n) {
    int p = n;
    
    while (p) {
        int lst = p % 10;
        if (lst != 0 && n % lst != 0) return false;
        p /= 10;
    }
    return true;
}
int32_t main()
{
    int n;
    cin >> n;
    
    while (n--) {
        int t;
        cin >> t;
        
        bool f = 0;
        
        while (!f) {
           f = check (t);
           if (f) break;
           t++;
        }
        
        cout << t << endl;
    }
    return 0;
}