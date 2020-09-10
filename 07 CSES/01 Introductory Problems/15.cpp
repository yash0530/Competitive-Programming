// CSES Chessboard and Queens
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

int ways;
string board[8];
string possible[8];

bool check() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (possible[i][j] == 'Q') {
				for (int k = 0; k < 8; k++) {
                    if (i != k and possible[k][j] == 'Q') return false;
                    if (j != k and possible[i][k] == 'Q') return false;
                }
                int a = i - 1, b = j - 1;
                while (a >= 0 and b >= 0) {
                    if (possible[a][b] == 'Q') return false;
                    a--; b--;
                }
                a = i + 1, b = j + 1;
                while (a < 8 and b < 8) {
                    if (possible[a][b] == 'Q') return false;
                    a++; b++;
                }
                a = i - 1, b = j + 1;
                while (a >= 0 and b < 8) {
                    if (possible[a][b] == 'Q') return false;
                    a--; b++;
                }
                a = i + 1, b = j - 1;
                while (a < 8 and b >= 0) {
                    if (possible[a][b] == 'Q') return false;
                    a++; b--;
                }
			}
		}
	}
	return true;
}

void checkPerms(int row) {
	if (row == 8) {
		ways++; return;
	}
	for (int i = 0; i < 8; i++) {
		if (board[row][i] != '*') {
			possible[row][i] = 'Q';
			if (check()) checkPerms(row + 1);
			possible[row][i] = '.';	
		}
	}
}

int32_t main() { fastio;
	for (int i = 0; i < 8; i++) {
		cin >> board[i];
		possible[i] = string(8, '.');
	}
	checkPerms(0);
	cout << ways << endl;
	return 0;
}