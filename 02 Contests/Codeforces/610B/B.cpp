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
	int t; cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector<int> arr(n), counts(n + 1, 0), prefix(n + 1, 0), rem(n + 1, p);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		prefix[0] = 0;
		sort(arr.begin(), arr.end());
		for (int i = 1; i <= n; i++) {
			prefix[i] = arr[i - 1] + prefix[i - 1];
			if (prefix[i] <= p) {
				counts[i] = counts[i - 1] + 1;
				rem[i] = rem[i - 1] - arr[i - 1];
			} else {
				counts[i] = counts[i - 1];
				rem[i] = rem[i - 1];
			}
		}
		if (arr[0] > p) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 0; i < k; i++) {
			int count = counts[i], np = rem[i];
			for (int j = i + k - 1; j < n; j += k) {
				if (arr[j] <= np) {
					np -= arr[j];
					count += k;
				}
			}
			ans = max(ans, count);
		}
		cout << ans << endl;
	}
	return 0;
}
