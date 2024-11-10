#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int M = 1e4 + 1;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, bitset<M>>> sqs;
    sqs.push_back({1, {}});
    sqs[0].second[0] = 1;

    bool ans = false;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (auto& sq : sqs) {
            sq.first *= a;
        }

        vector<pair<int, bitset<M>>> newsqs;
        bitset<M> ending;
        for (auto& sq : sqs) {
            int factor = sq.first;
            bitset<M> bits = sq.second;

            if (factor > m) factor = m + 1;

            if (!newsqs.empty() && newsqs.back().first == factor) {
                newsqs.back().second |= bits;
            } else {
                newsqs.push_back({factor, bits});
            }
        }

        for (auto& newsq : newsqs) {
            ending |= newsq.second << newsq.first;
        }

        ans = ending[m];
        newsqs.push_back({1, ending});
        swap(sqs, newsqs);
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
