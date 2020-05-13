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

struct Event{
	int d, w, t;
	bool operator < (const Event &e) const {
		return (w > e.w) or (w == e.w and d > e.d);
	}
};

int n;
const int maxN = 1e5 + 5, maxM = 205;
vector<pii> vals;
int dp[maxN][maxM];

int res(int ind, int avail) {
	if (ind >= n) return 0;
	int &ans = dp[ind][avail];
	if (ans == -1) {
		ans = INF;
		ans = min(ans, res(vals[ind].sc, avail) + vals[ind].fs);
		if (avail) {
			ans = min(ans, res(ind + 1, avail - 1));
		}
	}
	return ans;
}

int32_t main() { fastio;
	memset(dp, -1, sizeof dp);
	int m, k;
	cin >> n >> m >> k;
	vector<vector<Event>> ins(n), outs(n);
	for (int i = 0; i < k; i++) {
		int s, t, d, w;
		cin >> s >> t >> d >> w;
		s--; t--;
		ins[s].pb({ d, w, 1 });
		outs[t].pb({ d, w, 2 });
	}
	multiset<Event> actives;
	vals = vector<pii>(n);
	for (int i = 0; i < n; i++) {
		for (auto in : ins[i]) {
			actives.insert(in);
		}
		if (size(actives)) {
			vals[i] = { (*actives.begin()).w, (*actives.begin()).d };
		} else {
			vals[i] = { 0, i + 1 };
		}
		for (auto ou : outs[i]) {
			actives.erase(actives.find(ou));
		}
	}
	cout << res(0, m) << endl;
	return 0;
}
