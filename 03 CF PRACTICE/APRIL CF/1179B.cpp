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
	int n, m; cin >> n >> m;
	for (int i = 0; i < (n / 2); i++) {
		for (int j = 0; j < m; j++) {
			cout << i + 1 << " " << j + 1 << endl;
			cout << n - i << " " << m - j << endl;
		}
	}
	if (n & 1) {
		int mid = (n + 1) / 2;
		for (int i = 0; i < (m / 2); i++) {
			cout << mid << " " << i + 1 << endl;
			cout << mid << " " << m - i << endl;
		}
		if (m & 1) {
			cout << mid << " " << (m + 1) / 2 << endl;
		}
	}
    return 0;
}
