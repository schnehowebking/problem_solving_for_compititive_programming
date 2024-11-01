#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int m = (n + 1) / 2; 

        if (k > m) {
            cout << -1 << endl;
            continue;
        }

        vector<int> left_indices;
        for (int i = 1; i <= n; i += 2) {
            left_indices.push_back(i);
            if (left_indices.size() == m) break;
        }

        cout << left_indices.size() << endl;
        for (int idx : left_indices) {
            cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}
