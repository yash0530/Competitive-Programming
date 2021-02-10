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
		int n, m;
		cin >> n >> m;
		vector<string> mat(n);
		for (auto &x : mat) {
			cin >> x;
		}
		auto check = [&]() {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (mat[i][j] == mat[j][i]) {
						return make_pair(i, j);
					}
				}
			}
			return make_pair(-1LL, -1LL);
		};
		auto dewit = [&](int a, int b, int c) {
			cout << "YES" << endl;
			int half = (m - 2) / 2;
			cout << a << " ";
			for (int i = 0; i < (half / 2); i++) {
				cout << b << " " << a << " ";
			}
			cout << b << " " << c << " ";
			for (int i = 0; i < (half / 2); i++) {
				cout << b << " " << c << " ";
			} cout << endl;
		};
		if (m & 1) {
			cout << "YES" << endl;
			for (int i = 0; i < ((m + 1) / 2); i++) {
				cout << "1 2 ";
			} cout << endl;
		} else {
			pii val = check();
			if (val.fs != -1) {
				cout << "YES" << endl;
				cout << val.fs + 1 << " ";
				for (int i = 0; i < (m / 2); i++) {
					cout << val.sc + 1 << " " << val.fs + 1 << " ";
				} cout << endl;
			} else {
				if (n == 2) {
					cout << "NO" << endl;
				} else if (m % 4 == 0) {
					cout << "YES" << endl;
					if (mat[0][1] != mat[0][2]) {
						cout << 1 << " ";
						for (int i = 0; i < (m / 4); i++) {
							cout << "2 1 3 1 ";
						} cout << endl;
					} else if (mat[2][0] != mat[2][1]) {
						cout << 3 << " ";
						for (int i = 0; i < (m / 4); i++) {
							cout << "2 3 1 3 ";
						} cout << endl;
					} else {
						cout << 2 << " ";
						for (int i = 0; i < (m / 4); i++) {
							cout << "1 2 3 2 ";
						} cout << endl;
					}
				} else {
					if (mat[0][1] == mat[1][2]) {
						dewit(1, 2, 3);
					} else if (mat[1][2] == mat[2][0]) {
						dewit(2, 3, 1);
					} else if (mat[2][0] == mat[0][1]) {
						dewit(3, 1, 2);
					}
				}	
			}
		}
	}
	return 0;
}