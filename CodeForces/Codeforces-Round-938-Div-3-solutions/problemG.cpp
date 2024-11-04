#include <bits/stdc++.h>

using ll = long long int;

#define begin_all(x) (x).begin(), (x).end()

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

int findGCD(int a, int b) {
    while (b) {
        swap(a, b);
        b %= a;
    }
    return a;
}

void processTestCase() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int maxDivisor = 1;
    int commonGCD = findGCD(matrix[0][0], matrix[rows - 1][cols - 1]);
    vector<vector<char>> reachable(rows, vector<char>(cols));

    for (int divisor = 1; divisor * divisor <= commonGCD; ++divisor) {
        if (commonGCD % divisor != 0) {
            continue;
        }
        vector<int> candidates = {divisor, commonGCD / divisor};

        for (int candidate : candidates) {
            for (int i = 0; i < rows; ++i) {
                fill(reachable[i].begin(), reachable[i].end(), 0);
            }
            reachable[0][0] = 1;

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (matrix[i][j] % candidate != 0) {
                        continue;
                    }
                    if (!reachable[i][j] && i > 0) {
                        reachable[i][j] = (reachable[i - 1][j] == 1 ? 1 : 0);
                    }
                    if (!reachable[i][j] && j > 0) {
                        reachable[i][j] = (reachable[i][j - 1] == 1 ? 1 : 0);
                    }
                }
            }
            if (reachable[rows - 1][cols - 1]) {
                maxDivisor = max(maxDivisor, candidate);
            }
        }
    }

    cout << maxDivisor << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        processTestCase();
    }

    return 0;
}