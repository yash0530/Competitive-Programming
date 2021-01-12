#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

const int maxN = 5e3 + 5;
int dp[maxN][maxN];
int val[maxN];
int arr[maxN];
int n, k, q;

signed main() { fastio;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int j = 0; j <= k; j++) {
		for (int i = 0; i < n; i++) {
			if (j) {
				if (i) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				if (i != (n - 1)) {
					dp[i][j] = add(dp[i][j], dp[i + 1][j - 1]);
				}
			} else {
				dp[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			val[i] = add(val[i], mul(dp[i][j], dp[i][k - j]));
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = add(sum, mul(arr[i], val[i]));
	}
	int loc, curr;
	while (q--) {
		cin >> loc >> curr;
		sum = sub(sum, mul(arr[loc - 1], val[loc - 1]));
		arr[loc - 1] = curr;
		sum = add(sum, mul(arr[loc - 1], val[loc - 1]));
		cout << sum << endl;
	}
	return 0;
}