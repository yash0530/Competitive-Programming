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

const int maxN = 25;
int n;
int mat[maxN][maxN];
int arr[maxN];

const int N = (1LL << 21);
int dp[N];

int getMax(int mask) {
	int &ans = dp[mask];
	if (ans == -1) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (((1LL << i) & mask) == 0) {
				int curr = arr[i];
				for (int j = 0; j < n; j++) {
					if (i != j) {
						arr[j] += mat[j][i];
					}
				}
				curr += getMax(mask | (1LL << i));
				for (int j = 0; j < n; j++) {
					if (i != j) {
						arr[j] -= mat[j][i];
					}
				}
				ans = max(ans, curr);
			}
		}
	}
	return ans;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		memset(dp, -1, sizeof dp);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		cout << getMax(0) << endl;
	}
	return 0;
}