#include <bits/stdc++.h>
using namespace std;
const int c=200005;
int n, t[c], maxi;
void solve() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> t[i];
	}
	sort(t+1, t+n+1);
	int pos=1;
	for (int i=1; i<=n; i++) {
		while (pos<n && t[i]>=t[pos]+t[pos+1]) {
			pos++;
		}
		maxi=max(maxi, i-pos+1);
	}
 
	cout << n-maxi << "\n";
	maxi=0;
}
int main() {
	ios_base::sync_with_stdio(false);
	int w;
	cin >> w;
	while (w--) {
		solve();
	}
}
