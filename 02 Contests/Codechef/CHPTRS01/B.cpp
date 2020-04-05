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

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	uint a, b;
    	cin >> a >> b;
    	int max_pow = max(log2(a), log2(b));
    	vector<uint> res = { a ^ b };
    	for (int i = 1; i <= 64; i++) {
    		uint x = b & 1ULL;
    		b >>= 1ULL;
    		b |= ((1ULL << max_pow) * x);
    		res.push_back(a ^ b);
    	}
    	auto m = max_element(res.begin(), res.end());
    	cout << (m - res.begin()) << " " << *m << endl;
    }
    return 0;
}
