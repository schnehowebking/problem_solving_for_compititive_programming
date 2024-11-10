#include "bits/stdc++.h"
using namespace std;

#define RANGE(x) x.begin(), x.end()
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }

#ifdef DEBUG
#include "debug.h"
#else
#define TRACE(...) 42
#define ASSERT(...) 42
#endif

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

const int MAX_VAL = 1e9;
const int LIMIT = 1e4 + 1;

void process() {
    int n, target;
    cin >> n >> target;

    vector<pair<int, bitset<LIMIT>>> sequences;
    sequences.push_back({1, {}});
    sequences[0].second[0] = 1;
    bool found = false;

    for (int idx = 0; idx < n; ++idx) {
        int num;
        cin >> num;

        for (auto &[factor, bits] : sequences) {
            factor *= num;
        }

        vector<pair<int, bitset<LIMIT>>> newSeqs;
        bitset<LIMIT> finalState;

        for (auto &[factor, bits] : sequences) {
            if (factor > target) {
                factor = target + 1;
            }
            if (!newSeqs.empty() && newSeqs.back().first == factor) {
                newSeqs.back().second |= bits;
            } else {
                newSeqs.push_back({factor, bits});
            }
        }

        for (auto &[factor, bits] : newSeqs) {
            finalState |= bits << factor;
        }

        found = finalState[target];
        newSeqs.push_back({1, finalState});
        swap(sequences, newSeqs);
    }

    cout << (found ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--) {
        process();
    }

    return 0;
}
