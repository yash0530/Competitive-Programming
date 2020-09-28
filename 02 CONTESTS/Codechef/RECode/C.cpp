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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x;
		map<int, vector<int>> H;
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> x;
			s.insert(x);
			H[x].pb(i);
		}

		vector<int> itr(s.begin(), s.end());
		int res = 1, pos = H[itr[0]][0];
		int m = size(itr);
		for (int i = 1; i < m; i++) {
			auto x = upper_bound(H[itr[i]].begin(), H[itr[i]].end(), pos);
			if (x == H[itr[i]].end()) {
				res++;
				pos = H[itr[i]][0];
			} else {
				pos = *x;
			}
		}
		cout << res << endl;
	}
	return 0;
}
