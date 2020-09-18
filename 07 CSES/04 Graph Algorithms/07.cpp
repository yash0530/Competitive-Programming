// CSES Monsters
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
#define getMat(x, n, m, val) vector<vector<char>> x(n, vector<char> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int n, m;
vector<vector<int>> dirs = { { 1, 0, 'D', 'U' }, { -1, 0, 'U', 'D' }, { 0, 1, 'R', 'L' }, { 0, -1, 'L', 'R' } };

vector<vector<int>> performBFS(vector<vector<char>> mat, queue<vector<int>> Q, vector<vector<char>> vis) {
	vector<vector<int>> res;
	while (!Q.empty()) {
		vector<int> tp = Q.front(); Q.pop();
		if (tp[0] == 0 or tp[0] == (n - 1)) {
			res.pb(tp);
		}
		if (tp[1] == 0 or tp[1] == (m - 1)) {
			res.pb(tp);
		}
		for (auto d : dirs) {
			int ni = tp[0] + d[0];
			int nj = tp[1] + d[1];
			if ((ni >= 0) and (ni < n)) {
				if ((nj >= 0) and (nj < m)) {
					if (mat[ni][nj] != '#') {
						if (!vis[ni][nj]) {
							vis[ni][nj] = true;
							Q.push({ ni, nj, tp[2] + 1 });
						}
					}
				}
			}
		}
	}
	return res;
}

void printPath(vector<vector<char>> mat, int i, int j) {
	queue<vector<int>> Q;
	getMat(vis, n, m, 0);
	vis[i][j] = 'X';
	Q.push({ i, j });
	while (!Q.empty()) {
		auto tp = Q.front(); Q.pop();
		if (mat[tp[0]][tp[1]] == 'A') {
			string res;
			int ni = tp[0], nj = tp[1];
			while (vis[ni][nj] != 'X') {
				res.pb(vis[ni][nj]);
				for (auto d : dirs) {
					if (d[2] == vis[ni][nj]) {
						ni = ni + d[0];
						nj = nj + d[1];
						break;
					}
				}
			}
			cout << size(res) << endl;
			cout << res << endl;
			return;
		}
		for (auto d : dirs) {
			int ni = tp[0] + d[0];
			int nj = tp[1] + d[1];
			if ((ni >= 0) and (ni < n)) {
				if ((nj >= 0) and (nj < m)) {
					if (mat[ni][nj] != '#') {
						if (!vis[ni][nj]) {
							vis[ni][nj] = d[3];
							Q.push({ ni, nj });
						}
					}
				}
			}
		}
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	getMat(mat, n, m, 0);
	queue<vector<int>> monsters, people;
	getMat(vis_mon, n, m, 0);
	getMat(vis_people, n, m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'M')  {
				monsters.push({ i, j, 0 });
				vis_mon[i][j] = 1;
			}
			if (mat[i][j] == 'A') {
			 	people.push({ i, j, 0 });
			 	vis_people[i][j] = 1;
			}
		}
	}
	vector<vector<int>> people_dest = performBFS(mat, people, vis_people);
	vector<vector<int>> monster_dest = performBFS(mat, monsters, vis_mon);
	int r = -1, c = -1;
	map<pii, int> MP;
	for (auto x : monster_dest) {
		MP[{ x[0], x[1] }] = x[2];
	}
	for (auto p : people_dest) {
		if (MP.find({ p[0], p[1] }) != MP.end()) {
			if (MP[{ p[0], p[1] }] > p[2]) {
				r = p[0], c = p[1];
				break;
			}
		} else {
			r = p[0], c = p[1];
			break;
		}
	}
	if (r == -1) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		printPath(mat, r, c);
	}
	return 0;
}