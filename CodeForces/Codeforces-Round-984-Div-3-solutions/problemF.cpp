#include "bits/stdc++.h"
using namespace std;

long long computeXOR(long long limit) {
    long long result;
    switch (limit % 4) {
        case 0:
            result = limit;
            break;
        case 1:
            result = 1;
            break;
        case 2:
            result = limit + 1;
            break;
        case 3:
            result = 0;
            break;
        default:
            break;
    }
    return result;
}

long long calculate(long long left, long long shift, long long threshold) {
    long long baseXOR = computeXOR(left);
    long long shiftedValue = left >> shift;
    
    if ((left - (shiftedValue << shift)) < threshold) {
        if (shiftedValue == 0) {
            return baseXOR;
        }
        shiftedValue--;
    }
    
    long long tempXOR = computeXOR(shiftedValue);
    tempXOR <<= shift;
    
    if (shiftedValue % 2 == 0) {
        tempXOR += threshold;
    }
    
    return (baseXOR ^ tempXOR);
}

int main() {
    int testCount;
    cin >> testCount;
    
    while (testCount--) {
        long long left, right, shiftIndex, threshold;
        cin >> left >> right >> shiftIndex >> threshold;
        
        if (shiftIndex == 0) {
            cout << 0 << endl;
            continue;
        }
        
        cout << (calculate(right, shiftIndex, threshold) ^ calculate(left - 1, shiftIndex, threshold)) << endl;
    }
}