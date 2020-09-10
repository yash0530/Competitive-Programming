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

int n;
const int maxN = 3e5 + 5;
int dp[maxN], arr[maxN], next_gre[maxN];

int res(int pos) {
	if (pos == (n - 1)) {
		return 0;
	}
	int &ans = dp[pos];
	if (ans == -1) {
		ans = 1 + res(pos + 1);
		if (next_gre[pos] != -1) {
			ans = min(ans, 1 + res(next_gre[pos]));
		}
	}
	return ans;
}

int32_t main() { fastio;
	memset(dp, -1, sizeof dp);
	memset(next_gre, -1, sizeof next_gre);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() and arr[i] >= arr[s.top()]) {
			next_gre[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		int tp = s.top(); s.pop();
		if (!s.empty()) {
			next_gre[s.top()] = tp;
		}
	}
	for (int i = 0; i < n; i++) {
		cerr << next_gre[i] << " ";
	} cerr << endl;
	int ans = res(0);

	memset(dp, -1, sizeof dp);
	memset(next_gre, -1, sizeof next_gre);
	for (int i = 0; i < n; i++) {
		arr[i] *= -1;
	}
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() and arr[i] >= arr[s.top()]) {
			next_gre[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		int tp = s.top(); s.pop();
		if (!s.empty()) {
			next_gre[s.top()] = tp;
		}
	}
	for (int i = 0; i < n; i++) {
		cerr << next_gre[i] << " ";
	} cerr << endl;

	ans = min(ans, res(0));
	cout << ans << endl;

	return 0;
}