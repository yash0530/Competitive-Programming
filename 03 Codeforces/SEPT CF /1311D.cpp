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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		vector<vector<int>> divs(2e4 + 5);
		for (int i = 2; i <= 2e4; i++) {
			for (int j = i; j <= 2e4; j += i) {
				divs[j].pb(i);
			}
		}
		int a, b, c;
		cin >> a >> b >> c;
		int mn = a + b + c - 3;
		int aa = 1, ab = 1, ac = 1;
		for (int i = 1; i <= 2e4; i++) {
			int curr_a = 1, curr_d = a - 1;
			if (i > 1) {
				for (auto x : divs[i]) {
					if (curr_d > abs(x - a)) {
						curr_a = x;
						curr_d = abs(x - a);
					}
				}
			}
			int y1 = (c + i - (c % i));
			int y2 = max(i, (c - (c % i)));
			int curr_c = y1;
			if (abs(c - y1) > abs(c - y2)) {
				curr_c = y2;
			}
			int curr = abs(curr_a - a) + abs(c - curr_c) + abs(i - b);
			if (mn > curr) {
				mn = curr;
				aa = curr_a;
				ab = i;
				ac = curr_c;
			}
		}
		cout << mn << endl;
		cout << aa << " " << ab << " " << ac << endl;
	}
	return 0;
}