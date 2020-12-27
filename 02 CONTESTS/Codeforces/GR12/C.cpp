#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		char temp[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> temp[i][j];
			}
		}
		char best[n][n];
		int val = 100000000;
		for (int xx = 0; xx < 3; xx++) {
			int count = 0;
			char mat[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					mat[i][j] = temp[i][j];
				}
			}
			for (int i = xx; i < (2 * n + 5); i += 3) {
				for (int j = 0; j <= i; j++) {
					int x = i - j, y = j;
					if (x < n and y < n) {
						if (mat[x][y] == 'X') {
							if (x > 0 and x < (n - 1)) {
								if (mat[x - 1][y] == 'X' and mat[x + 1][y] == 'X') {
									mat[x][y] = 'O';
								}
							}
							if (y > 0 and y < (n - 1)) {
								if (mat[x][y - 1] == 'X' and mat[x][y + 1] == 'X') {
									mat[x][y] = 'O';
								}
							}
							if (x > 1) {
								if (mat[x - 2][y] == 'X' and mat[x - 1][y] == 'X') {
									mat[x][y] = 'O';
								}
							}
							if (x < (n - 2)) {
								if (mat[x + 2][y] == 'X' and mat[x + 1][y] == 'X') {
									mat[x][y] = 'O';
								}
							}
							if (y > 1) {
								if (mat[x][y - 2] == 'X' and mat[x][y - 1] == 'X') {
									mat[x][y] = 'O';
								}
							}
							if (y < (n - 2)) {
								if (mat[x][y + 2] == 'X' and mat[x][y + 1] == 'X') {
									mat[x][y] = 'O';
								}
							}
							if (mat[x][y] == 'O') {
								count++;
							}
						}
					}
				}
			}
			if (val > count) {
				val = count;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						best[i][j] = mat[i][j];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << best[i][j];
			} cout << endl;
		}
	}
	return 0;
}