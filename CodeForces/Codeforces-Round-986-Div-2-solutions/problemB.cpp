#include <bits/stdc++.h>
using namespace std;

void process() {
    long long n, b, c;
    cin >> n >> b >> c;
    
    if (b == 0) {
        if (n <= c) 
            cout << n << "\n";
        else if (c >= n - 2) 
            cout << n - 1 << "\n";
        else 
            cout << -1 << "\n";
    } else {
        if (n <= c) 
            cout << n << "\n";
        else 
            cout << n - max(0ll, 1 + (n - c - 1) / b) << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}
