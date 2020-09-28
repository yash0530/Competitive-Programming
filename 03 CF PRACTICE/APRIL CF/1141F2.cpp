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

bool cmp(pii &a, pii &b) {
	return a.sc < b.sc;
}

int32_t main() { fastio;
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map<int, vector<pii>> H;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			H[sum].pb({ i, j });
		}
	}
	vector<pii> ans;
	for (auto h : H) {
		auto x = h.sc;
		sort(x.begin(), x.end(), cmp);
		int prev = -1;
		vector<pii> poss;
		for (auto y : x) {
			if (y.fs > prev) {
				poss.pb(y);				
				prev = y.sc;
			}
		}
		if (size(poss) > size(ans)) {
			ans = poss;
		}
	}
	cout << size(ans) << endl;
	for (auto a : ans) {
		cout << a.fs + 1 << " " << a.sc + 1 << endl;
	}
	return 0;
}
