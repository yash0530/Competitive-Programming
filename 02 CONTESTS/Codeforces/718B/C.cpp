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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

vector<array<int, 2>> dirs = {
	{ 0, 1 }, // right
	{ 1, 0 }, // down
	{ 0, -1 }, // left
	{ -1, 0 } // up
};

signed main() { fastio;
	int n; cin >> n;
	getMat(mat, n, n, -1);
	for (int i = 0; i < n; i++) {
		cin >> mat[i][i];
	}
	for (int x = n - 1; x >= 0; x--) {
		int curr = mat[x][x];
		int count = 1;
		int i = x, j = x;

		int max = 501;
		while ((count < curr) and max--) {
			for (auto d : dirs) {
				int new_i = d[0] + i;
				int new_j = d[1] + j;
				if (new_i >= 0 and new_i < n) {
					if (new_j >= 0 and new_j < n) {
						if (new_i >= new_j and mat[new_i][new_j] == -1) {
							mat[new_i][new_j] = curr;
							i = new_i;
							j = new_j;
							count++;
							break;
						}		
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= j)
				cout << mat[i][j] << " ";
		} cout << endl;
	}

	return 0;
}