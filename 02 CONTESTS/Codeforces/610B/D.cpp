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

int getVal(string s) {
	cout << s << endl;
	int x; cin >> x;
	if (x == 0) exit(0);
	return x;
}

int32_t main() { fastio;
	string s1, s2;
	for (int i = 0; i < 300; i++) {
		s1.pb('a'); s2.pb('b');
	}
	int a = 300 - getVal(s1), b = 300 - getVal(s2);
	int n = a + b;
	string s;
	for (int i = 0; i < n; i++) {
		s.pb('a');
	}
	int curr = b;
	for (int i = 0; i < n - 1; i++) {
		s[i] = 'b';
		int now = getVal(s);
		if (now >= curr) {
			s[i] = 'a';
		}
		curr = min(now, curr);
	}
	if (curr) {
		s[n - 1] = 'b';
	}
	getVal(s);
	return 0;
}
