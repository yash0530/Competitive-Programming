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
		int h, n, stat, u, v;
		cin >> h >> n;
		vector<pii> bots, tops;
		for (int i = 0; i < n; i++) {
			cin >> stat >> u >> v;
			if (stat) {
				tops.pb({ u, v });
			} else {
				bots.pb({ u, v });
			}
		}
		sort(bots.begin(), bots.end());
		sort(tops.begin(), tops.end());

		int nb = size(bots), nt = size(tops);
		vector<int> res_t(nb), res_b(nt);

		// bottom -> top
		for (int i = 0; i < nb; i++) {
			vector<double> slopes;
			int loc = -1;
			for (int j = 0; j < nt; j++) {
				double slope = (double) (bots[i].sc - tops[j].sc) / (double) (bots[i].fs - tops[j].fs);
				slopes.pb(slope);
				if (tops[j].fs > bots[i].fs and loc == -1) {
					loc = j;
				}
			}
			int count = 0;
			if (loc == -1) {
				int bl = nt - 1;
				int prev = -INF;
				while (bl >= 0) {
					if (slopes[bl] > prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			} else {
				int bl = loc - 1;
				int prev = INF;
				while (loc < nt) {
					if (slopes[loc] < prev) {
						count++;
						prev = slopes[loc];
					}
					loc++;
				}
				prev = -INF;
				while (bl >= 0) {
					if (slopes[bl] > prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			}
			res_b[i] += count;
		}

		// bottom -> bottom
		for (int i = 0; i < nb; i++) {
			vector<double> slopes;
			int loc = -1;
			for (int j = 0, k = 0; j < nb; j++) {
				if (i != j) {
					double slope = (double) (bots[i].sc - bots[j].sc) / (double) (bots[i].fs - bots[j].fs);
					slopes.pb(slope);
					if (bots[j].fs > bots[i].fs and loc == -1) {
						loc = k;
					}
					k++;
				}
			}
			int count = 0;
			if (loc == -1) {
				int bl = nb - 2;
				int prev = INF;
				while (bl >= 0) {
					if (slopes[bl] < prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			} else {
				int bl = loc - 1;
				int prev = -INF;
				while (loc < nb - 1) {
					if (slopes[loc] > prev) {
						count++;
						prev = slopes[loc];
					}
					loc++;
				}
				prev = INF;
				while (bl >= 0) {
					if (slopes[bl] < prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			}
			res_b[i] += count;
		}

		deba(res_b);

		swap(tops, bots);
		swap(res_b, res_t);
		swap(nt, nb);

		// bottom -> top
		for (int i = 0; i < nb; i++) {
			vector<double> slopes;
			int loc = -1;
			for (int j = 0; j < nt; j++) {
				double slope = (double) (bots[i].sc - tops[j].sc) / (double) (bots[i].fs - tops[j].fs);
				slopes.pb(slope);
				if (tops[j].fs > bots[i].fs and loc == -1) {
					loc = j;
				}
			}
			int count = 0;
			if (loc == -1) {
				int bl = nt - 1;
				int prev = -INF;
				while (bl >= 0) {
					if (slopes[bl] > prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			} else {
				int bl = loc - 1;
				int prev = INF;
				while (loc < nt) {
					if (slopes[loc] < prev) {
						count++;
						prev = slopes[loc];
					}
					loc++;
				}
				prev = -INF;
				while (bl >= 0) {
					if (slopes[bl] > prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			}
			res_b[i] += count;
		}

		// bottom -> bottom
		for (int i = 0; i < nb; i++) {
			vector<double> slopes;
			int loc = -1;
			for (int j = 0, k = 0; j < nb; j++) {
				if (i != j) {
					double slope = (double) (bots[i].sc - bots[j].sc) / (double) (bots[i].fs - bots[j].fs);
					slopes.pb(slope);
					if (bots[j].fs > bots[i].fs and loc == -1) {
						loc = k;
					}
					k++;
				}
			}
			int count = 0;
			if (loc == -1) {
				int bl = nb - 2;
				int prev = INF;
				while (bl >= 0) {
					if (slopes[bl] < prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			} else {
				int bl = loc - 1;
				int prev = -INF;
				while (loc < nb - 1) {
					if (slopes[loc] > prev) {
						count++;
						prev = slopes[loc];
					}
					loc++;
				}
				prev = INF;
				while (bl >= 0) {
					if (slopes[bl] < prev) {
						count++;
						prev = slopes[bl];
					}
					bl--;
				}
			}
			res_b[i] += count;
		}

		deba(res_b);

		// // top -> bottom
		// for (int i = 0; i < nt; i++) {
		// 	for (int j = 0; j < )
		// }
	}
	return 0;
}
