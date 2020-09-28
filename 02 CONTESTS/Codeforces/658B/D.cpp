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

int N, target;
const int maxN = 4e3 + 5;
int arr[maxN];
int dp[maxN][maxN];

bool poss(int sum = 0, int pos = 0) {
	if (sum == target) {
		return true;
	}
	if (pos == N) {
		return false;
	}
	int &ans = dp[sum][pos];
	if (ans == -1) {
		ans = poss(sum, pos + 1);
		if ((sum + arr[pos]) <= target) {
			ans = ans or poss(sum + arr[pos], pos + 1);
		}
	}
	return ans;
}

int32_t main() {
	int t; cin >> t;
	memset(dp, -1, sizeof dp);
	while (t--) {
		int n; cin >> n;
		n *= 2;
		N = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		set<int> S;
		for (int i = 1; i <= n; i++) S.insert(-i);	
		int loc = n - 1;
		while (!S.empty()) {
			int curr = -(*S.begin());
			S.erase(S.begin());
			int size = 0;
			while (loc >= 0 and a[loc] != curr) {
				S.erase(-a[loc]);
				loc--;
				size++;
			}
			arr[N++] = size + 1;
			loc--;
		}
		target = (n / 2);
		if (poss()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) dp[i][j] = -1;
		}
	}
	return 0;
}