#include<bits/stdc++.h>
using namespace std;

int main() {
    int testCases, totalCount;
    cin >> testCases;
    
    while (testCases--) {
        int rows, cols;
        cin >> rows >> cols;
        int grid[rows + 3][cols + 3] = {0};
        
        for (int i = 0; i < rows; i++) {
            string rowInput;
            cin >> rowInput;
            int index = 0;
            for (char digit : rowInput) {
                grid[i][index] = digit - '0';
                index++;
            }
        }
        
        totalCount = 0;
        int top = 0, bottom = cols - 1, left = 0, right = rows - 1;
        
        while (top <= bottom && left <= right) {
            int currentValue = 0, occurrenceCount = 0;
            int iterations = 2;
            
            while (iterations--) {
                for (int i = top; i <= bottom; i++) {
                    currentValue = currentValue * 10 + grid[left][i];
                    currentValue %= 10000;
                    if (currentValue == 1543)
                        occurrenceCount++;
                }
                for (int i = left + 1; i <= right; i++) {
                    currentValue = currentValue * 10 + grid[i][bottom];
                    currentValue %= 10000;
                    if (currentValue == 1543)
                        occurrenceCount++;
                }
                for (int i = bottom - 1; i >= top; i--) {
                    currentValue = currentValue * 10 + grid[right][i];
                    currentValue %= 10000;
                    if (currentValue == 1543)
                        occurrenceCount++;
                }
                for (int i = right - 1; i >= left + 1; i--) {
                    currentValue = currentValue * 10 + grid[i][top];
                    currentValue %= 10000;
                    if (currentValue == 1543)
                        occurrenceCount++;
                }
            }
            if (occurrenceCount % 2 == 1) 
                occurrenceCount++;
            totalCount += occurrenceCount / 2;
            top++; left++; bottom--; right--;
        }
        cout << totalCount << endl;
    }
}