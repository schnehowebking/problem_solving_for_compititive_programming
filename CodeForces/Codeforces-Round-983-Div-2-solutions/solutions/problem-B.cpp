#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n, k;
	cin >> n >> k;
	if (n>=3 && (k==1 || k==n)) {
		cout << -1 << "\n";
		return;
	}
	if (n==1) {
		cout << 1 << "\n" << 1 << "\n";
		return;
	}
	cout << 3 << "\n";
	cout << 1 << " ";
	if (k%2) {
		cout << k-1 << " " << k+2 << "\n";
	} else {
		cout << k << " " << k+1 << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	int w;
	cin >> w;
	while (w--) {
		solve();
	}
}