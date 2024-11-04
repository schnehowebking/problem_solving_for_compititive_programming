#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
typedef double precision;

#define LINEBREAK "\n"
#define CONSTANT_PI (2.0 * acos(0.0))

inline int getCeil(int num, int divisor) {
    return (num + divisor - 1) / divisor;
}

inline int findAbs(int value1, int value2) {
    int diff = value1 - value2;
    return (diff < 0) ? -diff : diff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int count, costA, costB;
        cin >> count >> costA >> costB;

        int halfCount = count / 2;
        if (count % 2 == 0) {
            if ((count * costA) <= (halfCount * costB)) {
                cout << count * costA << LINEBREAK;
            } else {
                cout << halfCount * costB << LINEBREAK;
            }
        } else {
            if ((count * costA) <= (halfCount * costB + costA)) {
                cout << count * costA << LINEBREAK;
            } else {
                cout << halfCount * costB + costA << LINEBREAK;
            }
        }
    }
    return 0;
}