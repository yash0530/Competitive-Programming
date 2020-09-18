// CSES Labyrinth
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

int n, m;
const int maxN = 1005;
vector<vector<char>> dirs = { { 0, 1, 'R' }, { 1, 0, 'D' }, { -1, 0, 'U' }, { 0, -1, 'L' } };
char mat[maxN][maxN], vis[maxN][maxN];

void dewit(int a, int b) {
	queue<pii> Q;
	Q.push({ a, b });
	vis[a][b] = '_';
	while (!Q.empty()) {
		auto x = Q.front(); Q.pop();
		int i = x.fs, j = x.sc;
		for (auto d : dirs) {
			if ((i + d[0]) >= 0 and (i + d[0]) < n) {
				if ((j + d[1]) >= 0 and (j + d[1]) < m) {
					if ((vis[i + d[0]][j + d[1]] == 'A') and (mat[i + d[0]][j + d[1]] != '#')) {
						Q.push({ i + d[0], j + d[1] });
						vis[i + d[0]][j + d[1]] = d[2];
					}
				}
			}
		}
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	memset(vis, 65, sizeof vis);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((vis[i][j] == 'A') and (mat[i][j] == 'A')) {
				dewit(i, j);
			}
		}
	}
	string res = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'B' and vis[i][j] != 'A') {
				int iloc = i, jloc = j;
				while (vis[iloc][jloc] != '_') {
					for (auto d : dirs) {
						if (d[2] == vis[iloc][jloc]) {
							iloc -= d[0];
							jloc -= d[1];
							res.pb(d[2]);
						}
					}
				}
			}
		}
	}
	reverse(res.begin(), res.end());
	if (size(res)) {
		cout << "YES\n" << size(res) << endl << res << endl;
	} else {
		cout << "NO\n";
	}
	return 0;
}
