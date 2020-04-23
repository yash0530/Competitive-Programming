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
	string s; cin >> s;
	int res = 0;
	int n = size(s);
	int last_found = n;
	for (int i = n - 1; ~i; i--) {
		for (int k = 1; (k <= 4) and ((i + 2 * k) < last_found); k++) {
			if ((s[i] == s[i + k]) and (s[i] == s[i + 2 * k])) {
				res += (i + 1) * (last_found - (i + 2 * k));
				last_found = i + 2 * k;
			}
		}
	}
	cout << res << endl;
    return 0;
}
