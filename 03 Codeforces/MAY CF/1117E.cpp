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

int32_t main() { fastio;
	string s; cin >> s;
	int n = size(s);
	map<vector<char>, int> elems;
	int loc = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				elems[{ char('a' + i), char('a' + j), char('a' + k) }] = loc++;
				if (size(elems) == n) break;
			}
			if (size(elems) == n) break;
		}
		if (size(elems) == n) break;
	}
	vector<string> ops;
	vector<vector<char>> inps(n);
	for (int i = 0; i < 3; i++) {
		cout << "? ";
		int a = 0;
		for (auto e : elems) {
			cout << e.fs[i];
			inps[a].pb(e.fs[i]);
			a++; 
		} cout << endl;
		string x; cin >> x;
		ops.pb(x);
	}
	map<vector<char>, int> locs_map;
	for (int i = 0; i < n; i++) {
		locs_map[inps[i]] = i;
	}
	cout << "! ";
	vector<char> res(n);
	for (int i = 0; i < n; i++) {
		vector<char> alpha = { ops[0][i], ops[1][i], ops[2][i] };
		res[locs_map[alpha]] = s[i];
	}
	for (auto r : res) cout << r;
	cout << endl;
	return 0;
}
