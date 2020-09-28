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

int32_t main() {
	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> sz(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i] != -1 and b[i] != i) {
			sz[b[i]]++;
		}
	}
	queue<int> starts;
	for (int i = 1; i <= n; i++) {
		if (sz[i] == 0) {
			starts.push(i);
		}
	}
	int sum = 0;
	vector<int> res, bck;
	while (!starts.empty()) {
		int curr = starts.front(); starts.pop();
		if (a[curr] > 0) {
			if (b[curr] != -1 and b[curr] != curr) {
				a[b[curr]] += a[curr];
			}
			res.pb(curr);
		} else {
			bck.pb(curr);
		}
		sum += a[curr];
		if (b[curr] != -1 and b[curr] != curr) {
			sz[b[curr]]--;
			if (sz[b[curr]] == 0) {
				starts.push(b[curr]);
			}
		}
	}
	cout << sum << endl;
	for (auto r : res) {
		cout << r << " ";
	}
	reverse(bck.begin(), bck.end());
	for (auto x : bck) {
		cout << x << " ";
	} cout << endl;
}