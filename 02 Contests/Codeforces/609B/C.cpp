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

int n, k;
string dig;

int32_t main() { fastio;
	cin >> n >> k >> dig;
	string res(n, '0'); cout << n << endl;
	for (int i = 0; i < k; i++) {
		res[i] = dig[i];
		for (int j = i + k; j < n; j += k) {
			res[j] = dig[i];
		}
	}
	if (res < dig) {
		for (int i = k - 1; i >= 0; i--) {
			if (res[i] < '9') {
				for (int j = i; j < n; j += k) {
					res[j]++;
				}
				for (int j = i + 1; j < k; j++) {
					for (int c = j; c < n; c += k) {
						res[c] = '0';
					}
				}
				break;
			}
		}
	}
	cout << res << endl;
	return 0;
}
