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
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int a1 = arr[0], k = 0;
	vector<int> diffs(n - 1);
	for (int i = 1; i < n; i++) {
		diffs[i - 1] = arr[i] - arr[i - 1];
		if (diffs[i - 1] > 0) {
			k += diffs[i - 1];
		}
	}
	if ((a1 + k) < 0) {
		cout << ((a1 + k) / 2) << endl;
	} else {
		cout << (a1 + k + 1) / 2 << endl;
	}
	int q; cin >> q;
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		l--; r--;
		if (l == 0) {
			a1 += x;
		}
		if (l) {
			if (diffs[l - 1] > 0) k -= diffs[l - 1];
			diffs[l - 1] += x;
			if (diffs[l - 1] > 0) k += diffs[l - 1];
		}
		if (r != (n - 1)) {
			if (diffs[r] > 0) k -= diffs[r];
			diffs[r] -= x;
			if (diffs[r] > 0) k += diffs[r];
		}
		if ((a1 + k) < 0) {
			cout << ((a1 + k) / 2) << endl;
		} else {
			cout << (a1 + k + 1) / 2 << endl;
		}
	}
	return 0;
}