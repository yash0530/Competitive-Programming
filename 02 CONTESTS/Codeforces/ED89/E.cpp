#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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
	int n, m;
	cin >> n >> m;
	if (m > n) {
		cout << 0 << endl;
		exit(0);
	}
	vector<int> arr(n), brr(m);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> brr[i];
	}
	reverse(arr.begin(), arr.end());
	reverse(brr.begin(), brr.end());
	int mpos = 0, npos = 0;
	int ans = 1;
	while (mpos < (m - 1) and npos < n) {
		while (npos < n and brr[mpos] != arr[npos]) {
			if (brr[mpos] > arr[npos]) {
				cout << 0 << endl;
				exit(0);
			}
			npos++;
		}
		npos++;
		int count = 1;
		while (npos < n and brr[mpos] <= arr[npos]) {
			npos++;
			count++;
		}
		ans = mul(ans, count);
		mpos++;
	}
	if (npos == n) {
		cout << 0 << endl;
		exit(0);
	}
	if (brr.back() == *min_element(arr.begin() + npos, arr.end())) {
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
