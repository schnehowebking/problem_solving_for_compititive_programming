#include<bits/stdc++.h>

using namespace std;
 
int main() {
    int t, n;
    cin >> t;
    
    for (int tt = 0; tt < t; tt++) {
        cin >> n;
 
        int values[n];
        bool valid = true;
 
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            values[i] = v;
        }
 
        for (int i = 0; i < n - 1; i++) {
            if (abs(values[i] - values[i + 1]) != 7 && abs(values[i] - values[i + 1]) != 5) {
                valid = false;
                cout << "NO\n";
                break;
            }
        }
 
        if (valid) {
            cout << "YES\n";
        }
    }
}