#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000005;
const int MOD = 998244353;
long long elemCount, elements[MAX_SIZE], firstNonOnePos, powerOfTwo[MAX_SIZE], result;

void processCase() {
    cin >> elemCount;
    for (int i = 1; i <= elemCount; i++) {
        cin >> elements[i];
        if (!firstNonOnePos && elements[i] > 1) {
            firstNonOnePos = i;
        }
    }

    if (!firstNonOnePos) {
        cout << ((elemCount % 2) ? powerOfTwo[elemCount - 1] : 0) << "\n";
    } else {
        long long evenSum = 0, oddSum = 0;
        if (firstNonOnePos % 2 == 1) oddSum++;
        else evenSum++;

        for (int i = 1; i < firstNonOnePos; i++) {
            if ((firstNonOnePos - i) % 2 == 1) 
                oddSum = (oddSum + powerOfTwo[i - 1]) % MOD;
            else 
                evenSum = (evenSum + powerOfTwo[i - 1]) % MOD;
        }

        long long xorVal = 0;
        for (int i = firstNonOnePos; i <= elemCount; i++) {
            xorVal ^= elements[i];
            long long multiplier = (i == elemCount ? 1 : powerOfTwo[elemCount - i - 1]);

            if (xorVal == 0) {
                result = (result + ((firstNonOnePos % 2 == 0) ? (evenSum + oddSum) * multiplier : 0)) % MOD;
            }
            if (xorVal == 1) {
                result = (result + ((firstNonOnePos % 2 == 1) ? (evenSum + oddSum) * multiplier : 0)) % MOD;
            }
            if (xorVal > 1) {
                result = (result + ((firstNonOnePos % 2 == 1) ? oddSum * multiplier : evenSum * multiplier)) % MOD;
            }
        }
        cout << result << "\n";
    }

    result = 0;
    firstNonOnePos = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    powerOfTwo[0] = 1;
    for (int i = 1; i < MAX_SIZE; i++) {
        powerOfTwo[i] = 2 * powerOfTwo[i - 1] % MOD;
    }
    int testCases;
    cin >> testCases;
    while (testCases--) {
        processCase();
    }
}