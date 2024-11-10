#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while (n--) {
        long long p, q, r;
        cin >> p >> q >> r;
        
        string s;
        cin >> s;
        
        int x = 0, y = 0, cr = 0, t = 500;
        bool flag = false;
        
        while (t--) {
            if (s[cr] == 'E') x++;
            if (s[cr] == 'W') x--;
            if (s[cr] == 'N') y++;
            if (s[cr] == 'S') y--;
            
            if (x == q && y == r) {
                flag = true;
                break;
            }
            
            cr = (cr + 1) % p;
        }
        
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}