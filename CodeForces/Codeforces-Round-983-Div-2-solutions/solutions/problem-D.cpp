#include <bits/stdc++.h>
using namespace std;
const int c=200005;
int n, t[c];
bool ask(int a, int b) {
	cout << "? " << a << " " << b;
	cout.flush() << endl;
 
	int x;
	cin >> x;
	return 1-x;
}
bool res() {
	cout << "! ";
	for (int i=1; i<=n; i++) {
		cout << t[i] << " ";
	}
	cout.flush() << endl;
}
void solve() {
	cin >> n;
	n--;
	int pos=n;
	for (int i=n-1; i>=2; i--) {
		int res=ask(pos, i);
		if (res) {
			t[pos]=i;
			pos--;
		}
	}
	t[pos]=1;
	for (int i=1; i<=pos-1; i++) {
		t[i]=0;
	}
	res();
}
int main() {
	ios_base::sync_with_stdio(false);
	int w;
	cin >> w;
	while (w--) {
		solve();
	}
}