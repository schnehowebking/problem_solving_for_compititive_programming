#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        if (m == 0) {
            bool cnZ = false;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 0) {
                    cnZ = true;
                    break;
                }
            }
            cout << (cnZ ? "YES" : "NO") << endl;
            continue;
        }

        if (m == 1) {
            bool cnO = false;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 1) {
                    cnO = true;
                    break;
                }
            }
            cout << (cnO ? "YES" : "NO") << endl;
            continue;
        }

        int product = 1;
        bool cnA = false;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == m) {
                cnA = true;
                break;
            }
        }

        if (cnA) {
            cout << "YES" << endl;
            continue;
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }

        if (sum >= m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}