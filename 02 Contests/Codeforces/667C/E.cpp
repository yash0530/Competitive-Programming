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
		int n, k;
		cin >> n >> k;
		vector<int> x(n), y(n);
		for (auto &a : x) cin >> a;
		for (auto &a : y) cin >> a;
		sort(x.begin(), x.end());
		vector<int> counts(n);
		int prev = 0, curr = 0;
		while (curr < n) {
			int dist = x[curr] - x[prev];
			if (dist <= k) {
				counts[prev] = curr - prev + 1;
				curr++;
			} else {
				prev++;
				counts[prev] = counts[prev - 1] - 1;
			}
		}
		for (int i = prev + 1; i < n; i++) {
			counts[i] = n - i;
		}
		vector<int> max_counts(n);
		max_counts[n - 1] = counts[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			max_counts[i] = max(max_counts[i + 1], counts[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			curr = counts[i];
			if ((counts[i] + i) < n) {
				curr += max_counts[counts[i] + i];
			}
			ans = max(ans, curr);
		}
		cout << ans << endl;
	}
	return 0;
}