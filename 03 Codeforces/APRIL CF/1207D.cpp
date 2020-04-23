#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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

int32_t main() { fastio;
	int n; cin >> n;
	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].fs >> arr[i].sc;
	}
	vector<int> fact(n + 5);
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % HELL;
	}
	int res = fact[n];
	map<int, int> c1, c2;
	for (auto a : arr) {
		c1[a.fs]++;
		c2[a.sc]++;
	}
	int val = 1;
	for (auto x : c1) {
		val = (val * fact[x.sc]) % HELL;
	}
	res = (res - val + HELL) % HELL;
	val = 1;
	for (auto x : c2) {
		val = (val * fact[x.sc]) % HELL;
	}
	res = (res - val + HELL) % HELL;
	sort(arr.begin(), arr.end());
	bool poss = true;
	map<pii, int> c3;
	c3[arr[0]]++;
	for (int i = 1; i < n; i++) {
		if (arr[i].sc < arr[i - 1].sc) {
			poss = false;
			break;
		}
		c3[arr[i]]++;
	}
	if (poss) {
		val = 1;
		for (auto x : c3) {
			val = (val * fact[x.sc]) % HELL;
		}
		res = (res + val + HELL) % HELL;
	}
	cout << res << endl;
	return 0;
}
