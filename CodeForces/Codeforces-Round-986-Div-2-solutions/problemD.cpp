#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 250000;
int test_cases, n;
int stack_top[3];
int positions[3][MAX_N];
int parent[2][MAX_N];
char characters[3] = {'q', 'k', 'j'};

void explore(int current, int count) {
    if (current == 1) {
        cout << count << endl;
        return;
    }
    explore(parent[1][current], count + 1);
    cout << characters[parent[0][current]] << ' ' << current << endl;
}

void process() {
    cin >> n;
    
    for (int i = 0; i < 3; ++i) stack_top[i] = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> positions[i][j];
    
    for (int i = 0; i < 3; ++i) stack_top[i] = 1;

    for (int i = 2; i <= n; ++i) {
        bool found = false;
        for (int j = 0; j < 3; ++j) {
            if (positions[j][i] < positions[j][stack_top[j]]) {
                found = true;
                parent[0][i] = j;
                parent[1][i] = stack_top[j];
                break;
            }
        }
        
        if (!found) {
            if (i == n) {
                cout << "No" << endl;
                return;
            }
            continue;
        }

        for (int j = 0; j < 3; ++j) {
            if (positions[j][i] > positions[j][stack_top[j]]) {
                stack_top[j] = i;
            }
        }
    }

    cout << "Yes" << endl;
    explore(n, 0);
}

int main() {
    cin >> test_cases;
    while (test_cases--) {
        process();
    }
    return 0;
}
