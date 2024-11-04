#include <bits/stdc++.h>
using namespace std;

void processTestCase() {
    int length;
    cin >> length;
    string binaryString;
    cin >> binaryString;

    for (int maxLength = length; maxLength >= 1; maxLength--) {
        vector<int> modifiedBinary(length), adjustment(length + 1);
        
        for (int index = 0; index < length; index++) {
            modifiedBinary[index] = binaryString[index] - '0';
        }

        int toggleCount = 0; 
        for (int index = 0; index < length; index++) {
            toggleCount -= adjustment[index];
            modifiedBinary[index] ^= (toggleCount & 1);

            if (modifiedBinary[index] == 0) {
                if (index < length - maxLength + 1) {
                    adjustment[maxLength + index]++;
                    toggleCount++;
                    modifiedBinary[index] = 1;
                } else {
                    break;
                }
            }
        }

        bool isValid = true;
        for (int index = 1; index < maxLength; index++) {
            if (modifiedBinary[length - index] == 0) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            cout << maxLength << endl; 
            return;
        }
    }
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        processTestCase();
    }
    return 0;
}
