#include <bits/stdc++.h>
#define rep(i,x,y) for(int i = x; i <= y; i++)
#define mid ((l + r) >> 1)
#define lch (rt << 1)
#define rch (rt << 1 | 1)
 
using namespace std;
 
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
 
void solve() {
    int n;
    cin >> n;
    int tot = 0;
    rep(i,0,2*n-1) {
        int x;
        cin >> x;
        tot += x;
    }
 
    int ans;
    if (tot <= n) ans = tot;
    else ans = 2 * n - tot;
    cout << (tot & 1) << ' ' << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int T;
    cin >> T;
 
    while (T--) {
        solve();
    }
 
    return 0;
}