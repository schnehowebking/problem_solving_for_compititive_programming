#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void processTest() {
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < 2 * n; i++) {
        int val;
        cin >> val;
        sum += val;
    }

    int result;
    if (sum <= n) {
        result = sum;
    } else {
        result = 2 * n - sum;
    }

    cout << (sum % 2) << ' ' << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        processTest();
    }

    return 0;
}