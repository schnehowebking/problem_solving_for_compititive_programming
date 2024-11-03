#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 200005;
int count_elements, inpArray[MAX_SIZE], max_length;

void findSolution() {
    cin >> count_elements;
    for (int i = 1; i <= count_elements; i++) {
        cin >> inpArray[i];
    }
    sort(inpArray + 1, inpArray + count_elements + 1);

    int start = 1;
    for (int i = 1; i <= count_elements; i++) {
        while (start < count_elements && inpArray[i] >= inpArray[start] + inpArray[start + 1]) {
            start++;
        }
        max_length = max(max_length, i - start + 1);
    }

    cout << count_elements - max_length << "\n";
    max_length = 0;
}

int main() {
    ios::sync_with_stdio(false);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        findSolution();
    }
}