// CSES Counting Rooms
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
vector<pii> dirs = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
char mat[maxN][maxN];
bool vis[maxN][maxN];
 
void dfs(int i, int j) {
	vis[i][j] = true;
	for (auto d : dirs) {
		if ((i + d.fs) >= 0 and (i + d.fs) < n) {
			if ((j + d.sc) >= 0 and (j + d.sc) < m) {
				if (!vis[i + d.fs][j + d.sc] and mat[i + d.fs][j + d.sc] == '.')
					dfs(i + d.fs, j + d.sc);
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
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] and mat[i][j] == '.') {
				count++;
				dfs(i, j);
			}
		}
	}
	cout << count << endl;
	return 0;
}