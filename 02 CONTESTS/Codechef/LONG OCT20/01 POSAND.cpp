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

bool po2(int n) {
	return (n & (n - 1)) == 0;
}

void getSeq(int n) {
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	if (po2(n)) {
		cout << -1 << endl;
		return;
	}
	if (n == 3) {
		cout << "1 3 2" << endl;
		return;
	}
	if (n == 5) {
		cout << "2 3 1 5 4" << endl;
		return;
	}
	vector<int> halva = { 2, 3, 1, 5, 4 };
	for (int i = 6; i <= n; i++) {
		if (po2(i)) {
			halva.pb(i + 1);
			halva.pb(i);
			i++;
		} else {
			halva.pb(i);
		}
	}
	for (auto alpha : halva) {
		cout << alpha << " ";
	}
	cout << endl;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		getSeq(n);
	}
	return 0;
}