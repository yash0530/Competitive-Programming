#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int getMin(vector<int> a, vector<int> b) {

	int ans = a[0] + a[1] + a[2], t1;

	if (min(a[0], b[2]) > 0) {
		t1 = min(a[0], b[2]);
		a[0] -= t1;
		b[2] -= t1;
		ans = min(ans, getMin(a, b));
		a[0] += t1;
		b[2] += t1;
	}

	if (min(a[1], b[0]) > 0) {
		t1 = min(a[1], b[0]);
		a[1] -= t1;
		b[0] -= t1;
		ans = min(ans, getMin(a, b));
		a[1] += t1;
		b[0] += t1;
	}

	if (min(a[2], b[1]) > 0) {
		t1 = min(a[2], b[1]);
		a[2] -= t1;
		b[1] -= t1;
		ans = min(ans, getMin(a, b));
		a[2] += t1;
		b[1] += t1;
	}

	for (int i = 0; i < 3; i++) {
		if (min(a[i], b[i]) > 0) {
			t1 = min(a[i], b[i]);
			a[i] -= t1;
			b[i] -= t1;
			ans = min(ans, getMin(a, b));
			a[i] += t1;
			b[i] += t1;
		}
	}

	return ans;	
}

int getMax(vector<int> a, vector<int> b) {
	return min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
}

int32_t main() { fastio;
	int n; cin >> n;
	vector<int> a(3), b(3);
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];

	cout << getMin(a, b) << " " << getMax(a, b) << endl;
	return 0;
}