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
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	int ac = 0, bc = 0;
	for (auto x : s) {
		ac += x == 'a';
		bc += x == 'b';
	}
	for (auto x : t) {
		ac += x == 'a';
		bc += x == 'b';
	}
	if ((ac & 1) or (bc & 1)) {
		cout << -1 << endl;
	} else {
		vector<int> pos1, pos2;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				if (s[i] == 'a') {
					pos1.pb(i);
				} else {
					pos2.pb(i);
				}
			}
		}
		vector<pii> moves;
		for (int i = 0; i < size(pos1) - 1; i += 2) {
			moves.pb({ pos1[i], pos1[i + 1] });
		}
		for (int i = 0; i < size(pos2) - 1; i += 2) {
			moves.pb({ pos2[i], pos2[i + 1] });
		}
		if (size(pos1) & 1) {
			moves.pb({ pos1.back(), pos1.back() });
			moves.pb({ pos1.back(), pos2.back() });
		}
		cout << size(moves) << endl;
		for (auto m : moves) {
			cout << m.fs + 1 << " " << m.sc + 1 << endl;
		}
	}
	return 0;
}
