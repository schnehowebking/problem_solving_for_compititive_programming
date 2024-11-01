#include <bits/stdc++.h>
using namespace std;
const int c=500005;
long long n, t[c], sum, ans[c], pref[c], sok=1e17;
int valt(int a) {
	while (a>n) a-=n;
	while (a<=0) a+=n;
	return a;
}
void solve() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> t[i];
		sum+=t[i];
	}
	if (n==1) {
		cout << 0 << "\n";
		sum=0;
		return;
	}
 
	while (sum%n) {
		ans[2]++;
		t[1]++, t[2]+=2, t[3]++;
		sum+=4;
	}
 
	long long avg=sum/n;
 
	int ert=1, kov=3;
 
	for (int i=1; i<n; i++) {
		long long dif=avg-t[ert];
		//cout << "fontos " << dif << "\n";
		// 1 3 eseten dif=1
		// 4 6 1 ++
		// 5 7 2 --
		pref[valt(kov+1)]+=dif;
		pref[valt(kov+1)+n-1]-=dif;
 
		pref[valt(kov)]-=dif;
		pref[valt(kov)+n-1]+=dif;
 
		t[ert]+=dif;
		t[kov]-=dif;
 
		ert=kov;
		kov=valt(kov+2);
 
		/*for (int i=1; i<=2*n; i++) {
            cout << i << " " << pref[i] << "\n";
		}*/
	}
 
 
	for (int i=3; i<=2*n; i++) {
		pref[i]+=pref[i-2];
	}
 
	for (int i=1; i<=n; i++) {
		ans[i]=ans[i]+sok+pref[i]+pref[i+n];
		//ans[i]-=sok;
		//cout << "fontos " << i << " " << pref[i] << " " << pref[i+n] << "\n";
	}
 
	for (int i=1; i<=n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
 
	for (int i=0; i<=2*n; i++) {
		ans[i]=0, pref[i]=0, t[i]=0;
	}
	sum=0;
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	int w;
	cin >> w;
	while (w--) {
		solve();
	}
}