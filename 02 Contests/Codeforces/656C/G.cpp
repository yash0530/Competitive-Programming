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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> top(n), bot(n);
		for (int i = 0; i < n; i++) cin >> top[i];
		for (int i = 0; i < n; i++) cin >> bot[i];

		vector<int> freq(n + 1);
		vector<vector<int>> pos(n + 1);
		for (int i = 0; i < n; i++) {
			freq[top[i]]++;
			freq[bot[i]]++;
			pos[top[i]].pb(i);
			pos[bot[i]].pb(i);
		}
		bool poss = true;
		for (int i = 1; i <= n; i++) {
			if (freq[i] != 2) poss = false;
		}
		if (poss) {
			int res = 0;
			vector<int> r;
			vector<int> vis(n + 1);
			for (int i = 0; i < n; i++) {
				if (top[i] != bot[i]) {
					if (!vis[i]) {
						vis[i] = true;
						
						int curr = i;
						int elem = bot[curr];

						int t1 = 1, t2 = 0;
						vector<int> r1, r2;
						r1.pb(i + 1);

						while (true) {
							int new_loc;
							if (pos[elem][0] == curr) {
								new_loc = pos[elem][1];
							} else {
								new_loc = pos[elem][0];
							}
							if (vis[new_loc]) break;

							curr = new_loc;
							if (top[curr] == elem) {
								t1++;
								elem = bot[curr];
								r1.pb(curr + 1);
							} else {
								t2++;
								elem = top[curr];
								r2.pb(curr + 1);
							}
							vis[curr] = true;
						}
						if (t1 < t2) {
							res += t1;
							for (auto x : r1) r.pb(x);
						} else {
							res += t2;
							for (auto x : r2) r.pb(x);
						}
					}
				}
			}
			cout << res << endl;
			for (auto x : r) cout << x << " ";
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}