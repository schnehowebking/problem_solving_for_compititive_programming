#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed << setprecision(1)
#define MAX_INT INT_MAX
#define MIN_INT INT_MIN
#define LIMIT 1000000000000000000LL
#define MIN_LIMIT LLONG_MIN
#define GRID_SIZE 300000
#define NEWLINE "\n"

typedef pair<int, int> Pair;
typedef tuple<int, int, int> Triple;

int square(int x) {
    return x * x;
}

int powerOfThree(int x) {
    int result = 1;
    while (x--) result *= 3;
    return result;
}

int rows, cols, elements, dpTable[2505][1024], X[2505], Y[2505], Points[2505];
char grid[55][55];

int computeScore(int index, int radius) {
    int score = 0;
    for (int i = max(1, X[index] - radius); i <= min(X[index] + radius, rows); i++) {
        for (int j = max(1, Y[index] - radius); j <= min(Y[index] + radius, cols); j++) {
            if (grid[i][j] == '#' && square(i - X[index]) + square(j - Y[index]) <= square(radius)) {
                score++;
            }
        }
    }
    return score * Points[index];
}

void processTestCase() {
    cin >> rows >> cols >> elements;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= elements; i++) {
        cin >> X[i] >> Y[i] >> Points[i];
    }

    for (int i = 1; i <= elements; i++) {
        for (int mask = 0; mask < 1024; mask++) {
            if (__builtin_popcount(mask) > i) continue;
            dpTable[i][mask] = dpTable[i - 1][mask];

            for (int radius = 0; radius < 10; radius++) {
                if ((1 << radius) & mask) {
                    dpTable[i][mask] = max(dpTable[i][mask], dpTable[i - 1][mask ^ (1 << radius)] + computeScore(i, radius + 1));
                }
            }
        }
    }

    int maxScore = 0;
    for (int mask = 0; mask < 1024; mask++) {
        int penalty = 0;
        for (int i = 0; i < 10; i++) {
            if ((1 << i) & mask) {
                penalty += powerOfThree(i + 1);
            }
        }
        maxScore = max(maxScore, dpTable[elements][mask] - penalty);
    }
    cout << maxScore << NEWLINE;
}

int main() {
    FAST_IO;
    int testCases = 1;
    cin >> testCases;
    while (testCases--) processTestCase();
    return 0;
}