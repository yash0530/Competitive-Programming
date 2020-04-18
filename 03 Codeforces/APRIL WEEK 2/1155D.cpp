#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)
#define size(a) (int) a.size()

int32_t main() { fastio;
	int n, x;
	cin >> n >> x;
	int res = 0;
	vector<int> pref(n), suff(n), arr(n), sum(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			sum[i] = arr[i];
			pref[i] = max(0LL, arr[i]);
		} else {
			sum[i] = sum[i - 1] + arr[i];
			pref[i] = max(0LL, pref[i - 1] + arr[i]);
		}
		res = max(res, pref[i]);
	}
	suff[n - 1] = max(0LL, arr[n - 1]);
	for (int i = n - 2; ~i; i--) {
		suff[i] = max(0LL, suff[i + 1] + arr[i]);
	}

	int left_max = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			res = max(res, x * sum[i] + left_max);
		} else {
			res = max(res, suff[i + 1] + x * sum[i] + left_max);
		}
		left_max = max(left_max, pref[i] - x * sum[i]);
	}
	cout << res << endl;
    return 0;
}
