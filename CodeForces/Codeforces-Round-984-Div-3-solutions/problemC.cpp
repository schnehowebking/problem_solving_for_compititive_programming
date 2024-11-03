#include<bits/stdc++.h>
using namespace std;
using int64 = long long;

void processQueries() {
    string binaryString;
    cin >> binaryString;
    int64 numQueries;
    cin >> numQueries;

    set<int64> patternPositions;
    int strLength = binaryString.length();

    for (int i = 0; i <= strLength - 4; i++) {
        if (binaryString[i] == '1' && binaryString[i + 1] == '1' && binaryString[i + 2] == '0' && binaryString[i + 3] == '0') {
            patternPositions.insert(i);
        }
    }

    while (numQueries--) {
        int index, newValue;
        cin >> index >> newValue;
        index--; 
        char replacementChar = (newValue == 1) ? '1' : '0';

        if (binaryString[index] != replacementChar) {
            binaryString[index] = replacementChar;

            for (int i = max(0, index - 3); i <= min(strLength - 4, index); i++) {
                if (patternPositions.count(i) && !(binaryString[i] == '1' && binaryString[i + 1] == '1' && binaryString[i + 2] == '0' && binaryString[i + 3] == '0')) {
                    patternPositions.erase(i);
                }
                if (binaryString[i] == '1' && binaryString[i + 1] == '1' && binaryString[i + 2] == '0' && binaryString[i + 3] == '0') {
                    patternPositions.insert(i);
                }
            }
        }

        cout << (!patternPositions.empty() ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 testCases;
    cin >> testCases;
    while (testCases--) {
        processQueries();
    }
    return 0;
}