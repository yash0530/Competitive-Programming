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
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	int c1 = 0, c2 = 0;
	vector<int> alpha;
	for (int i = 0; i < n; i++) {
		c1 += (a[i] == '1');
		c2 += (b[i] == '1');
		if (a[i] != b[i]) {
			if (a[i] == '1') alpha.pb(1);
			else alpha.pb(0);
		}
	}
	if (c1 != c2) {
		cout << -1 << endl;
	} else {
		vector<int> ones, zeros;
		for (auto x : alpha) {
			if (x) {
				if (zeros.empty()) {
					ones.pb(1);
				} else {
					int al = zeros.back(); zeros.pop_back();
					ones.pb(al + 1);
				}
			} else {
				if (ones.empty()) {
					zeros.pb(1);
				} else {
					int al = ones.back(); ones.pop_back();
					zeros.pb(al + 1);
				}
			}
		}
		cout << size(ones) + size(zeros) << endl;
	}
	return 0;
}