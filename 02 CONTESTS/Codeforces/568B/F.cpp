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

int32_t main() { fastio;
	int n, m, x, y, c;
	cin >> n >> m;
	vector<int> friends((1 << 10));
	vector<vector<pii>> pizzas((1 << 10));
	set<int> masks;
	for (int i = 0; i < n; i++) {
		cin >> x;
		int mask = 0;
		for (int i = 0; i < x; i++) {
			cin >> y;
			mask |= (1 << y);
		}
		friends[mask]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> c >> x;
		int mask = 0;
		for (int i = 0; i < x; i++) {
			cin >> y;
			mask |= (1 << y);
		}
		masks.insert(mask);
		pizzas[mask].pb({ c, i + 1 });
	}
	for (auto &p : pizzas) {
		sort(p.begin(), p.end());
	}
	vector<int> avails(masks.begin(), masks.end());
	int res = 0, cost = INF, a = 1, b = 1;
	for (int i = 0; i < size(avails); i++) {
		for (int j = i; j < size(avails); j++) {
			int count = 0;
			int mask = avails[i] | avails[j];
			for (int k = 1; k < (1 << 10); k++) {
				if ((mask | k) == mask) {
					count += friends[k];
				}
			}
 			if (i == j and size(pizzas[avails[i]]) > 1) {
				if (count > res) {
					res = count;
					cost = pizzas[avails[i]][0].fs + pizzas[avails[j]][1].fs;
					a = pizzas[avails[i]][0].sc, b = pizzas[avails[j]][1].sc;
				} else if (count == res) {
					if ((pizzas[avails[i]][0].fs + pizzas[avails[j]][1].fs) < cost) {
						cost = pizzas[avails[i]][0].fs + pizzas[avails[j]][1].fs;
						a = pizzas[avails[i]][0].sc, b = pizzas[avails[j]][1].sc;
					}
				}
			}
			if (i != j) {
				if (count > res) {
					res = count;
					cost = pizzas[avails[i]][0].fs + pizzas[avails[j]][0].fs;
					a = pizzas[avails[i]][0].sc, b = pizzas[avails[j]][0].sc;
				} else if (count == res) {
					if ((pizzas[avails[i]][0].fs + pizzas[avails[j]][0].fs) < cost) {
						cost = pizzas[avails[i]][0].fs + pizzas[avails[j]][0].fs;
						a = pizzas[avails[i]][0].sc, b = pizzas[avails[j]][0].sc;
					}
				}
			}
		}
	}
	cout << a << " " << b << endl;
	return 0;
}
