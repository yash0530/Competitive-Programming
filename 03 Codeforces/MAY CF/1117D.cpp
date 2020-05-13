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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

vector<vector<int>> mat_mul(vector<vector<int>> a, vector<vector<int>> b) {
	getMat(res, size(a), size(b[0]), 0);
	for (int i = 0; i < size(a); i++) {
		for (int j = 0; j < size(b[0]); j++) {
			for (int k = 0; k < size(a[0]); k++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % HELL;
			}
		}
	}
	return res;
}

vector<vector<int>> mat_pow(vector<vector<int>> base, int pow) {
	vector<vector<int>> res = base; pow--;
	while (pow) {
		if (pow & 1) {
			res = mat_mul(res, base);
		}
		base = mat_mul(base, base);
		pow >>= 1;
	}
	return res;
}

int32_t main() { fastio;
	int n, m;
	cin >> n >> m;
	if (n < m) {
		cout << 1 << endl;
	} else if (n == m) { 
		cout << 2 << endl;
	} else {
		getMat(trans, m, m, 0);
		trans[0][0] = 1; trans[0][m - 1] = 1;
		for (int i = 1; i < m; i++) {
			trans[i][i - 1] = 1;
		}
		getMat(vars, m, 1, 1);
		vars[0][0] = 2;
		trans = mat_pow(trans, n - m);
		cout << mat_mul(trans, vars)[0][0] << endl;
	}
	return 0;
}
