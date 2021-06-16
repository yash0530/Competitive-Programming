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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

string _not(string a) {
	for (auto &x : a) {
		if (x == '1') x = '0';
		else x = '1';
	}
	reverse(_all(a));
	while (size(a) and a.back() == '0') a.pop_back();
	if (size(a) == 0) a.push_back('0');
	reverse(_all(a));
	return a;
}


void solve() {
	string S, E;
	cin >> S >> E;
	unordered_set<string> sss;
	queue<pair<string, int>> Q;
	Q.push({ S, 0 });

	while (!Q.empty()) {
		auto xx = Q.front(); Q.pop();
		if (size(xx.fs) > 25) continue;
		if (sss.find(xx.fs) != sss.end()) continue;
		sss.insert(xx.fs);
		if (xx.fs == E) {
			cout << xx.sc << endl;
			return;
		}
		if (xx.sc == 43) continue;
		string nt = _not(xx.fs);
		Q.push({ nt, xx.sc + 1 });
		if (xx.fs != "0") {
			xx.fs.pb('0');
			Q.push({ xx.fs, xx.sc + 1 });
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

signed main() { fastio;

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}