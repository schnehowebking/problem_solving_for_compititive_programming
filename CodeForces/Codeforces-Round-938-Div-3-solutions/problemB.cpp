#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 250000 + 5;
long long arr[MAX_SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long test_cases, size, incr_c, incr_d;
    cin >> test_cases;

    while (test_cases--) {
        cin >> size >> incr_c >> incr_d;

        for (int idx = 0; idx < size * size; idx++) {
            cin >> arr[idx];
        }

        sort(arr, arr + size * size);

        bool isValid = true;
        vector<long long> generated_values;

        for (int row = 1; row <= size; row++) {
            for (int col = 1; col <= size; col++) {
                generated_values.push_back(arr[0] + (row - 1) * incr_c + (col - 1) * incr_d);
            }
        }

        sort(generated_values.begin(), generated_values.end());

        for (int idx = 0; idx < size * size; idx++) {
            if (arr[idx] != generated_values[idx]) {
                isValid = false;
                break;
            }
        }

        cout << (isValid ? "YES" : "NO") << "\n";
    }
    return 0;
}