#include <bits/stdc++.h>

using namespace std;

void processQueries() {
    int sizeN, sizeK, queries;
    cin >> sizeN >> sizeK >> queries;
    
    vector<vector<int>> matrix(sizeK, vector<int>(sizeN));
    
    for (int row = 0; row < sizeN; row++) {
        for (int col = 0; col < sizeK; col++) {
            cin >> matrix[col][row];
        }
    }

    for (int col = 0; col < sizeK; col++) {
        for (int row = 1; row < sizeN; row++) {
            matrix[col][row] |= matrix[col][row - 1];
        }
    }

    while (queries--) {
        int conditions;
        cin >> conditions;
        int lowerBound = 0, upperBound = sizeN - 1;
        
        while (conditions--) {
            int rIndex, cValue;
            char comparison;
            cin >> rIndex >> comparison >> cValue;
            rIndex--;

            if (comparison == '<') {
                int idx = lower_bound(matrix[rIndex].begin(), matrix[rIndex].end(), cValue) - matrix[rIndex].begin();  
                upperBound = min(upperBound, idx - 1);
            } else {
                int idx = upper_bound(matrix[rIndex].begin(), matrix[rIndex].end(), cValue) - matrix[rIndex].begin(); 
                lowerBound = max(lowerBound, idx);
            }
        }

        if (lowerBound > upperBound) {
            cout << "-1\n";
        } else {
            cout << lowerBound + 1 << '\n';
        }
    }
}

int main() {
    int testCount = 1;
    while (testCount--) {
        processQueries();
    }
    return 0;
}