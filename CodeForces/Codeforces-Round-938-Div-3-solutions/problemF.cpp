#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAX_SIZE = 210;
const int MOD = 1e9 + 7;
int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE];

void initializeDP() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            for (int k = 0; k < MAX_SIZE; k++) {
                if ((i + j + k) == 0) continue;

                int maxValue = 0;
                if (i > 0) maxValue = max(maxValue, dp[i - 1][j][k]);
                if (j > 0) maxValue = max(maxValue, dp[i][j - 1][k]);
                if (k > 0) maxValue = max(maxValue, dp[i][j][k - 1]);

                dp[i][j][k] = maxValue;

                if ((i % 2 == j % 2) && (j % 2 == k % 2)) {
                    dp[i][j][k]++;
                }
            }
        }
    }
}

void computeResult() {
    int x, y, z, additional;
    cin >> x >> y >> z >> additional;

    int finalResult = dp[x][y][z];
    finalResult += additional / 2;
    cout << finalResult << endl; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCases;
    cin >> testCases;
    
    initializeDP(); 
    while (testCases--) {
        computeResult(); 
    }

    return 0;
}