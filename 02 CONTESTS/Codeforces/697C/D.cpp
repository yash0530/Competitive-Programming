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

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> arr(n), brr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		for (auto &b : brr) {
			cin >> b;
		}
		priority_queue<int> pqA, pqB;
		for (int i = 0; i < n; i++) {
			if (brr[i] == 1) {
				pqA.push(arr[i]);
			} else {
				pqB.push(arr[i]);
			}
		}
		int ans = 0;
		int xx = INF;
		while (!pqA.empty() or !pqB.empty()) {
			if (!pqA.empty()) {
				int x = pqA.top();
				if (x >= k) {
					ans++;
					k -= x;
					xx = x;
					break;
				}
			}
			if (!pqB.empty()) {
				int x = pqB.top();
				if (x >= k) {
					ans += 2;
					k -= x;
					break;
				}
			}
			if (!pqA.empty() and !pqB.empty()) {
				if ((pqA.top() * 2) <= pqB.top()) {
					k -= pqB.top();
					ans += 2;
					pqB.pop();
				} else {
					k -= pqA.top();
					xx = pqA.top();
					ans++;
					pqA.pop();
				}
			} else if (!pqA.empty()) {
				k -= pqA.top();
				xx = pqA.top();
				ans++;
				pqA.pop();
			} else {
				k -= pqB.top();
				ans += 2;
				pqB.pop();
			}
		}
		if (k <= 0) {
			if (abs(k) >= xx) {
				ans--;
			}
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}