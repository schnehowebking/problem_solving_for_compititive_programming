#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MAX_SIZE = 2e5 + 10;

void processTestCase() {
    int itemCount, maxElements;
    cin >> itemCount >> maxElements;

    int values[maxElements + 10] = {0};

    for (int i = 1; i <= maxElements; i++) {
        int index, quantity;
        cin >> index >> quantity;
        values[index] += quantity;
    }

    sort(values + 1, values + maxElements + 1);
    
    int64 sumResult = 0;
    if (maxElements <= itemCount) {
        for (int i = 1; i <= maxElements; i++) {
            sumResult += values[i];
        }
    } else {
        for (int i = maxElements - itemCount + 1; i <= maxElements; i++) {
            sumResult += values[i];
        }
    }

    cout << sumResult << endl;
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        processTestCase();
    }
    return 0;
}