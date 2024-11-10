#include<bits/stdc++.h>
using namespace std;

void process() {
    int n, m, v;
    cin >> n >> m >> v;
    
    vector<int> a(n);
    vector<long long> prefixSum(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefixSum[i] = (i == 0) ? a[i] : prefixSum[i - 1] + a[i];
    }

    int sum = 0, velocity = 0;
    vector<int> segments(n);
    for (int i = n - 1; i >= 0; --i) {
        sum += a[i];
        if (sum >= v) {
            sum = 0;
            ++velocity;
        }
        segments[i] = velocity;
    }

    long long maxPrefix = -1;
    sum = velocity = 0;
    
    int left = 0, right = n - 1, thresholdIndex = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (segments[mid] >= m) {
            thresholdIndex = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (thresholdIndex > 0) {
        maxPrefix = prefixSum[thresholdIndex - 1];
    }

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum >= v) {
            sum = 0;
            ++velocity;
            
            int l = i + 1, r = n - 1, bestIndex = i - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (velocity + segments[mid] >= m) {
                    bestIndex = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (velocity >= m) bestIndex = n;
            if (bestIndex != i - 1) {
                maxPrefix = max(maxPrefix, prefixSum[bestIndex - 1] - prefixSum[i]);
            }
        }
    }

    cout << maxPrefix << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}