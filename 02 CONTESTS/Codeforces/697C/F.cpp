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

bool isPoss(vector<vector<int>> &mat, int n) {
	for (int col = 0; col < n; col++) {
		if (mat[0][col] == 1) {
			for (int row = 0; row < n; row++) {
				mat[row][col] = 1 - mat[row][col];
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (mat[i][0] == 1) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 1 - mat[i][j];
			}
		}
	}
	int sum = 0;
	for (auto x : mat) {
		for (auto y : x) {
			sum += y;
		}
	}
	return sum == 0;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		getMat(arr, n, n, 0);
		getMat(brr, n, n, 0);
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < n; j++) {
				arr[i][j] = s[j] - '0';
			}
		}
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < n; j++) {
				brr[i][j] = s[j] - '0';
				if (brr[i][j] == arr[i][j]) {
					brr[i][j] = 0;
				} else {
					brr[i][j] = 1;
				}
			}
		}
		bool check = isPoss(brr, n);
		for (int i = 0; i < n; i++) {
			brr[0][i] = 1 - brr[0][i];
		}
		check = check or isPoss(brr, n);
		if (check) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}