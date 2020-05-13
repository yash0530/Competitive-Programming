#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

void solve() {
	int u; cin >> u;
	vector<pair<int, string>> vs;
	int x; string y;
	set<int> alpha;
	for (int i = 0; i < 1e4; i++) {
		cin >> x >> y;
		vs.pb({ x, y });
		for (auto a : y) {
			alpha.insert(a);
		}
	}

	if (u == 2) {
		sort(vs.begin(), vs.end());
		vector<char> res;
		for (auto v : vs) {
			if (size(res) == 10) {
				break;
			}
			if (v.fs < 10) {
				if (find(res.begin(), res.end(), v.sc[0]) == res.end()) {
					res.pb(v.sc[0]);
				}
			}
		}
		bool done = false;
		for (auto v : vs) {
			for (auto a : v.sc) {
				if (find(res.begin(), res.end(), a) == res.end()) {
					cout << a;
					done = true;
					break;
				}
			}
			if (done) break;
		}
		for (auto r : res) cout << r; cout << endl;
	} else {
		map<char, int> M;
		for (auto a : alpha) {
			M[a] = 11;
		}
		for (auto v : vs) {
			string num = to_string(v.fs);
			string chr = v.sc;
			if (size(num) == size(chr)) {
				M[chr[0]] = min(M[chr[0]], (int) (num[0] - '0'));
			}
		}
		vector<pair<int, char>> final;
		for (auto l : M) {
			final.pb({ l.sc, l.fs });
		}
		sort(final.begin(), final.end());
		cout << final.back().sc;
		for (int i = 0; i < 9; i++) {
			cout << final[i].sc;
		} cout << endl;
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
