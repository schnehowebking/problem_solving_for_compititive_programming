#include<bits/stdc++.h>
using namespace std;

void solveProblem() {
    long long n, k;
    cin >> n >> k;
    vector<long long> elements(n);

    for (int i = 0; i < n; i++) 
        cin >> elements[i];

    long long leftQuota = (k + 1) / 2;
    long long rightQuota = k / 2;
    long long maxElements = 0;
    int left = 0;
    int right = n - 1;

    while (leftQuota > 0 && left < n) {
        if (leftQuota >= elements[left]) {
            maxElements++;
            leftQuota -= elements[left];
            elements[left] = -1;
        } else {
            elements[left] -= leftQuota;
            leftQuota = 0;
        }
        left++;
    }

    while (rightQuota > 0 && right >= 0) {
        if (elements[right] == -1) break;
        if (rightQuota >= elements[right]) {
            maxElements++;
            rightQuota -= elements[right];
            elements[right] = -1;
        } else {
            elements[right] -= rightQuota;
            rightQuota = 0;
        }
        right--;
    }

    cout << maxElements << endl;
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solveProblem();
    }
    return 0;
}