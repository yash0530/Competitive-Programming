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
	int n, m;
	cin >> n >> m;
	vector<string> mat(n);
	int row_pref[n][m], col_pref[n][m];
	memset(row_pref, 0, sizeof row_pref);
	memset(col_pref, 0, sizeof col_pref);
	vector<pair<int, int>> locs;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != '#' and mat[i][j] != '.') {
				locs.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				row_pref[i][j] = (mat[i][j] == '#');
			} else {
				row_pref[i][j] = row_pref[i][j - 1] + (mat[i][j] == '#');
			}
		}
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				col_pref[i][j] = (mat[i][j] == '#');
			} else {
				col_pref[i][j] = col_pref[i - 1][j] + (mat[i][j] == '#');
			}
		}
	}

	int k; cin >> k;
	vector<pair<char, int>> ints(k);
	for (int i = 0; i < k; i++) {
		cin >> ints[i].first >> ints[i].second;
	}

	string res = "";
	for (auto l : locs) {
		auto og = l;
		char sight = mat[l.first][l.second];
		bool valid = true;
		for (auto x : ints) {
			if (x.first == 'N') {
				l.first -= x.second;
				if (l.first < 0) {
					valid = false;
					break;
				}
				if (col_pref[l.first][l.second] != col_pref[og.first][og.second]) {
					valid = false;
					break;
				}
			} else if (x.first == 'S') {
				l.first += x.second;
				if (l.first == n) {
					valid = false;
					break;
				}
				if (col_pref[l.first][l.second] != col_pref[og.first][og.second]) {
					valid = false;
					break;
				}
			} else if (x.first == 'W') {
				l.second -= x.second;
				if (l.second < 0) {
					valid = false;
					break;
				}
				if (row_pref[l.first][l.second] != row_pref[og.first][og.second]) {
					valid = false;
					break;
				}
			} else {
				l.second += x.second;
				if (l.second == m) {
					valid = false;
					break;
				}
				if (row_pref[l.first][l.second] != row_pref[og.first][og.second]) {
					valid = false;
					break;
				}
			}
			if (mat[l.first][l.second] == '#') {
				valid = false;
				break;
			}
			og = l;
		}
		if (valid) {
			res.push_back(sight);
		}
	}

	if (size(res)) {
		sort(res.begin(), res.end());	
		cout << res << endl;
	} else {
		cout << "no solution" << endl;
	}
    return 0;
}
