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
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int n, m, a, b; cin >> n >> m;
	int w[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	multiset<int> okay[n + 1];
	pii guests[m + 1];
	for (int j = 1; j <= m; j++) {
		cin >> a >> b;
		okay[a].insert(j);
		okay[b].insert(j);
		guests[j] = { a, b };
	}
	set<pii> qu;
	for (int i = 1; i <= n; i++) {
		qu.insert({ size(okay[i]) - w[i], i });
	}
	vector<int> res;
	while (!qu.empty() and (size(res) < m)) {
		pii tp = *qu.begin(); qu.erase(qu.begin());
		if (tp.fs > 0) break;
		int food = tp.sc;
		for (auto x : okay[food]) {
			res.pb(x);
			int curr;
			if (guests[x].fs == food) {
				curr = guests[x].sc;
			} else {
				curr = guests[x].fs;
			}
			pii ee = *qu.find({ size(okay[curr]) - w[curr], curr });
			qu.erase(ee);
			ee.fs--;
			okay[curr].erase(okay[curr].find(x));
			qu.insert(ee);
		}
	}
	reverse(_all(res));
	if (size(res) == m) {
		cout << "ALIVE" << endl;
		for (auto r : res) {
			cout << r << " ";
		} cout << endl;
	} else {
		cout << "DEAD" << endl;
	}
	return 0;
}