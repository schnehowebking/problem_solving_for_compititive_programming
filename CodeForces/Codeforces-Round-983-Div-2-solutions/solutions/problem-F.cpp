#include <bits/stdc++.h>
using namespace std;
const int c=1000005, mod=998244353;
long long n, t[c], pos, po[c], ans;
void solve() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> t[i];
		if (!pos && t[i]>1) {
			pos=i;
		}
	}
 
	if (!pos) {
		if (n%2) {
			cout << po[n-1] << "\n";
		} else {
			cout << 0 << "\n";
		}
	} else {
		long long ps=0, pn=0;
		if (pos%2) ps++;
		else pn++;
 
		for (int i=1; i<pos; i++) {
			if ((pos-i)%2) ps=(ps+po[i-1])%mod;
			else pn=(pn+po[i-1])%mod;
		}
 
		long long xo=0;
		for (int i=pos; i<=n; i++) {
			xo^=t[i];
			long long mul=(i==n ? 1 : po[n-i-1]);
			if (xo==0) {
				if (pos%2==0) ans=(ans+(ps+pn)*mul)%mod;
			}
			if (xo==1) {
				if (pos%2) ans=(ans+(ps+pn)*mul)%mod;
			}
			if (xo>1) {
				if (pos%2) ans=(ans+ps*mul)%mod;
				else ans=(ans+pn*mul)%mod;
			}
		}
 
		cout << ans << "\n";
 
	}
	ans=0, pos=0;
}
int main() {
	ios_base::sync_with_stdio(false);
	po[0]=1;
	for (int i=1; i<c; i++) {
		po[i]=2*po[i-1]%mod;
	}
	int w;
	cin >> w;
	while (w--) {
		solve();
	}
}