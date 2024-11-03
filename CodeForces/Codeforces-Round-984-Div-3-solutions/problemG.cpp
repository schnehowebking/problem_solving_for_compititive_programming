#include<bits/stdc++.h>
using namespace std;
#define int long long

int query(int left, int right) {
    cout << "xor " << left << ' ' << right << endl;
    int result;
    cin >> result;
    return result;
}

int combinedXOR, sizeLimit;

void findValues1() {
    int lowerBound = 2, upperBound = sizeLimit, finalAnswer = 2;
    
    while (lowerBound <= upperBound) {
        int middle = (lowerBound + upperBound) / 2;
        if (query(1, middle) != combinedXOR) {
            lowerBound = middle + 1;
            finalAnswer = middle;
        } else {
            upperBound = middle - 1;
        }
    }

    int cValue = finalAnswer + 1;
    int intermediateXOR = combinedXOR ^ cValue;
    lowerBound = 1, upperBound = cValue - 1, finalAnswer = 0;

    while (lowerBound <= upperBound) {
        int middle = (lowerBound + upperBound) / 2;
        if (query(1, middle) == 0) {
            lowerBound = middle + 1;
            finalAnswer = middle;
        } else {
            upperBound = middle - 1;
        }
    }
    
    int aValue = finalAnswer + 1;
    int bValue = intermediateXOR ^ aValue;

    vector<int> results = {aValue, bValue, cValue};
    sort(results.begin(), results.end());
    aValue = results[0];
    bValue = results[1];
    cValue = results[2];

    cout << "ans ";
    cout << aValue << ' ' << bValue << ' ' << cValue << endl;
}

void findValues2() {
    for (int i = 60; i >= 0; i--) {
        int mask = (1LL << i) - 1;
        if (mask > sizeLimit) continue;
        int value = query(1, mask);
        
        if (value) { // Detected a bit
            int firstValue = value;
            int lowBound = value + 1, highBound = sizeLimit, cValue = sizeLimit;
            
            while (lowBound <= highBound) {
                int middle = (lowBound + highBound) / 2;
                if (query(middle, sizeLimit) == 0) {
                    highBound = middle - 1;
                    cValue = middle - 1;
                } else {
                    lowBound = middle + 1;
                }
            }
            
            int secondValue = combinedXOR ^ firstValue ^ cValue;
            vector<int> results = {firstValue, secondValue, cValue};
            sort(results.begin(), results.end());
            firstValue = results[0];
            secondValue = results[1];
            cValue = results[2];

            cout << "ans ";
            cout << firstValue << ' ' << secondValue << ' ' << cValue << endl;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        cin >> sizeLimit;

        combinedXOR = query(1, sizeLimit);
        if (combinedXOR != 0) 
            findValues1();
        else 
            findValues2();
    }
}
