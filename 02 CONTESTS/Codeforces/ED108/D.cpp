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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

int n;
const int maxN = 5005;
int A[maxN], B[maxN], pref[maxN];

int ans;
void solve(int low, int high, int val) {
	ans = max(ans, val);
	if (low == 1 or high == n) {
		return;
	}
	val -= (A[low - 1] * B[low - 1] + A[high + 1] * B[high + 1]); 
	val += (A[high + 1] * B[low - 1] + A[low - 1] * B[high + 1]);
	solve(low - 1, high + 1, val);
}

signed main() { fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
	}
	for (int i = 1; i <= n; i++) {
		pref[i] += pref[i - 1] + A[i] * B[i];
	}

	ans = pref[n];
	for (int i = 1; i <= n; i++) {
		solve(i, i, pref[n]);
	}
	for (int i = 1; i < n; i++) {
		solve(i, i + 1, pref[n] - (A[i] * B[i] + A[i + 1] * B[i + 1]) + (A[i + 1] * B[i] + A[i] * B[i + 1]));
	}
	cout << ans << endl;
	return 0;
}