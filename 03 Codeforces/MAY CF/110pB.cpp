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

bool isPalin(string x) {
	int n = size(x);
	int low = 0, high = n - 1;
	while (low < high) {
		if (x[low] != x[high]) return false;
		low++; high--;
	}
	return true;
}

int32_t main() { fastio;
	string s; cin >> s;
	int n = size(s);
	map<int, int> m;
	for (auto x : s) {
		m[x]++;
	}
	int mx = 0;
	for (auto x : m) {
		mx = max(x.sc, mx);
	}
	if ((n & 1 and mx == n - 1) or (mx == n)) {
		cout << "Impossible" << endl;
	} else {
		for (int i = 1; i < n; i++) {
			string x = s.substr(i, n - i) + s.substr(0, i);
			if (x.compare(s) and isPalin(x)) {
				cout << 1 << endl;
				exit(0);
			}
		}
		cout << 2 << endl;
	}
	return 0;
}
