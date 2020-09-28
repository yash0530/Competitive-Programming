#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)
#define size(a) (int) a.size()

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		vector<string> moves(n);
		for (int i = 0; i < n; i++) {
			cin >> grid[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> moves[i];
		}

		// intitalize graph
		vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int r = i, c = j;
				if (moves[i][j] == 'U') {
					r--;
				} else if (moves[i][j] == 'L') {
					c--;
				} else if (moves[i][j] == 'R') {
					c++;
				} else {
					r++;
				}
				parent[i][j] = { r, c };
			}
		}

		// binary lifting
		for (int d = 0; d < 22; d++) {
			vector<vector<pair<int, int>>> new_p(n, vector<pair<int, int>>(m));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					auto p = parent[i][j];
					new_p[i][j] = parent[p.first][p.second];
				}
			}
			parent = new_p;
		}

		// getting solution
		vector<vector<bool>> reached(n, vector<bool>(m));
		vector<vector<bool>> b_reached(n, vector<bool>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				auto p = parent[i][j];
				reached[p.first][p.second] = true;
				if (grid[i][j] == '0') {
					b_reached[p.first][p.second] = true;
				}
			}
		}

		int all = 0, black = 0;
		for (auto a : reached) {
			for (auto b : a) all += b;
		}
		for (auto a : b_reached) {
			for (auto b : a) black += b;
		}
		cout << all << " " << black << endl;
	}
    return 0;
}
