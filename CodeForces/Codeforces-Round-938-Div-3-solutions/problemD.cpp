#include <bits/stdc++.h>
#define int64 long long
#define newline '\n'
using namespace std;

const int MAX_SIZE = 200005;
int64 values[MAX_SIZE];

void executeTest() {
    int64 matchCount = 0, totalCount = 0;
    map<int64, int64> requiredMap, currentWindow;
    int n, m, minMatches;
    cin >> n >> m >> minMatches;

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 1; i <= m; i++) {
        int item;
        cin >> item;
        requiredMap[item]++;
    }

    for (int right = 1, left = 1; right <= n; right++) {
        currentWindow[values[right]]++;
        if (currentWindow[values[right]] <= requiredMap[values[right]]) {
            matchCount++;
        }

        if (right > m) {
            currentWindow[values[left]]--;
            if (currentWindow[values[left]] < requiredMap[values[left]]) {
                matchCount--;
            }
            left++;
        }

        if (right >= m && matchCount >= minMatches) {
            totalCount++;
        }
    }
    cout << totalCount << newline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        executeTest();
    }

    return 0;
}
