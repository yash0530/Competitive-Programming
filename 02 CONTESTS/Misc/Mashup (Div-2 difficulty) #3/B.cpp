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

bool overlap(vector<int> a, vector<int> b) {
	if (a[0] < b[0]) {
		return a[1] >= b[0];
	} else if (a[0] > b[0]) {
		return b[1] >= a[0];
	}
	return true;
}
int32_t main() { fastio;
	int p, q, l, r;
	cin >> p >> q >> l >> r;

	vector<vector<int>> A(p, { 0, 0 }), B(q, { 0, 0 });
	for (int i = 0; i < p; i++) {
		cin >> A[i][0] >> A[i][1];
	}
	for (int i = 0; i < q; i++) {
		cin >> B[i][0] >> B[i][1];
	}

	int count = 0;
	for (int i = l; i <= r; i++) {
		bool poss = false;
		for (auto x : A) {
			for (auto y : B) {
				if (overlap(x, { y[0] + i, y[1] + i })) {
					poss = true;
					break;
				}
			}
			if (poss) {
				count++;
				deb(i);

				break;
			}
		}
	}
	cout << count << endl;

    return 0;
}
