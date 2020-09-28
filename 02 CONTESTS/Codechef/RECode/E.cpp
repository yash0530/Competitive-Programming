#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL 163577857LL 
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

const int maxN = 200005;
int fact[maxN], invFact[maxN];

int nck(int n, int k) {
    return (invFact[n - k] * ((fact[n] * invFact[k]) % HELL)) % HELL;
}

int combs(int n, int m, int a, int b, int r) {
	int res = 0;
	for (int i = 0; i <= r; i++) {
		res = (res + nck(n, a + i) * nck(m, b + i)) % HELL;
	}
	return res;
}

int32_t main() { fastio;

	fact[0] = 1; invFact[0] = 1;
    for (int i = 1; i < maxN; i++) {
        fact[i] = (i * fact[i - 1]) % HELL;
        invFact[i] = fastpow(fact[i], HELL - 2, HELL);
    }

	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n;
		int one = 0, zero = 0, minus = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			one += x == 1;
			zero += x == 0;
			minus += x == -1;
		}
		for (int sum = -n; sum <= n; sum++) {
			int res = 0;
			if (sum >= -1 * minus and sum <= one) {
				int a = max(-sum, 0LL);
				int b = max(sum, 0LL);
				int r = min(minus - a, one - b);
				res = combs(minus, one, a, b, r);
				res = (res * fastpow(2, zero)) % HELL;
				if (sum == 0) {
					res = (res - 1) % HELL;
				}
			}
			cout << res << " ";
		} cout << endl;
	}
	return 0;
}
