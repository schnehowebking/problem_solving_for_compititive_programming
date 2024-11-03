#include <bits/stdc++.h>
using namespace std;

const int MAX_ELEMENTS = 500005;
long long elementCount, values[MAX_ELEMENTS], totalSum, result[MAX_ELEMENTS], prefix[MAX_ELEMENTS], largeConstant = 1e17;

int wrapIndex(int index) {
    while (index > elementCount) index -= elementCount;
    while (index <= 0) index += elementCount;
    return index;
}

void processTestCase() {
    cin >> elementCount;
    for (int i = 1; i <= elementCount; i++) {
        cin >> values[i];
        totalSum += values[i];
    }

    if (elementCount == 1) {
        cout << 0 << "\n";
        totalSum = 0;
        return;
    }

    while (totalSum % elementCount) {
        result[2]++;
        values[1]++, values[2] += 2, values[3]++;
        totalSum += 4;
    }

    long long averageValue = totalSum / elementCount;
    int currentIndex = 1, nextIndex = 3;

    for (int i = 1; i < elementCount; i++) {
        long long difference = averageValue - values[currentIndex];

        prefix[wrapIndex(nextIndex + 1)] += difference;
        prefix[wrapIndex(nextIndex + 1) + elementCount - 1] -= difference;

        prefix[wrapIndex(nextIndex)] -= difference;
        prefix[wrapIndex(nextIndex) + elementCount - 1] += difference;

        values[currentIndex] += difference;
        values[nextIndex] -= difference;

        currentIndex = nextIndex;
        nextIndex = wrapIndex(nextIndex + 2);
    }

    for (int i = 3; i <= 2 * elementCount; i++) {
        prefix[i] += prefix[i - 2];
    }

    for (int i = 1; i <= elementCount; i++) {
        result[i] = result[i] + largeConstant + prefix[i] + prefix[i + elementCount];
    }

    for (int i = 1; i <= elementCount; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i <= 2 * elementCount; i++) {
        result[i] = 0, prefix[i] = 0, values[i] = 0;
    }
    totalSum = 0;
}

int main() {
    ios::sync_with_stdio(false);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        processTestCase();
    }
}