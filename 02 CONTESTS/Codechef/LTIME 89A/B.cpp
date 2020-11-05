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
#define _all(aa) aa.begin(), aa.end()

const int maxN = 1e5 + 5;

int32_t main() { fastio;
	int t; cin >> t;
	vector<vector<int>> sv(maxN);
	for (int i = 2; i < maxN; i++) {
		for (int j = i; j < maxN; j += i) {
			sv[j].pb(i);
		}
	}
	while (t--) {
		int n; cin >> n;
		vector<int> diff_arr(n + 1);
		vector<pii> intervals(maxN, { -1, -1 });
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			auto primes = sv[x];
			for (auto p : primes) {
				if (intervals[p].fs == -1) {
					intervals[p].fs = i;
					intervals[p].sc = i;
				} else {
					intervals[p].sc = i;
				}
			}
		}
		for (auto inv : intervals) {
			if (inv.fs != -1) {
				diff_arr[inv.fs]++;
				diff_arr[inv.sc]--;
			}
		}
		for (int i = 1; i <= n; i++) {
			diff_arr[i] += diff_arr[i - 1];
		}
		int res = -1;
		for (int i = 0; i < (n - 1); i++) {
			if (diff_arr[i] == 0) {
				res = i + 1;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}