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

const int maxN = 2e2 + 5;
int cache[maxN][maxN];

int result(int n, int k) {
	if ((n < 0) or (k < 0)) {
		return 0;
	}
	if ((n * (n - 1) / 2) < k) {
		k = n * (n - 1) / 2;
	}
	int &ans = cache[n][k];
	if (ans == -1) {
		ans = result(n, k - 1) % 2;
		ans = (ans + result(n - 1, k) + 8) % 2;
		ans = (ans - result(n - 1, k - n) + 8) % 2;
	}
	ans = ans % 2;
	return ans;
}

int DP(int n, int k) {
	cache[0][0] = 1;
	if (n == 0) {
		return 0;
	}
	if (n == k) {
		return (result(n - 1, k) + 1) % 2;
	}
	return result(n - 1, k) % 2;
}

int nck(int n, int r) {
	int x = n - r, a = 0, b = 0;
	while (n) {
		a += n / 2; n /= 2;
	}
	while (x) {
		b += x / 2; x /= 2;
	}
	while (r) {
		b += r / 2; r /= 2;
	}
	return (a == b);
}

const int maxP = 141423;
int penta[maxP];

int32_t main() { fastio;
	int t; cin >> t;
	for (int i = 0; i < maxP; i++) {
		penta[i] = i * (3 * i - 1) / 2;
	}
	memset(cache, -1, sizeof cache);
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (n < 200) {
			cout << DP(n, k) % 2 << endl;
			continue;			
		}
		int val = 0;
		int N = n + k - 1, K = k, pos = 1;
		int nn = N, kk = K;
		while (nn > 0 and kk >= 0) {
			val = (nck(nn, kk) + val) % 2;
			nn = N - penta[pos] - pos;
			kk = K - penta[pos] - pos;
			pos++;
		}
		N = n + k - 1, K = k, pos = 1;
		nn = N - penta[pos]; kk = K - penta[pos++];
		while (nn > 0 and kk >= 0) {
			val = (nck(nn, kk) + val) % 2;
			nn = N - penta[pos];
			kk = K - penta[pos];
			pos++;
		}
		cout << val << endl;
	}
}