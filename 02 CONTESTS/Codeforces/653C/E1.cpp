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
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> pqA, pqB, pqAB;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b and c) {
			pqAB.push(a);
		} else if (b) {
			pqA.push(a);
		} else if (c) {
			pqB.push(a);
		}
	}
	int count = 0, ans = 0;
	while ((count < k) and (!pqAB.empty() or (!pqA.empty() and !pqB.empty()))) {
		if (!pqAB.empty() and (!pqA.empty() and !pqB.empty())) {
			int t1 = pqAB.top();
			int t2 = pqA.top() + pqB.top();
			if (t1 > t2) {
				ans += t2;
				pqA.pop(); pqB.pop();
			} else {
				ans += t1;
				pqAB.pop();
			}
		} else if (!pqAB.empty()) {
			ans += pqAB.top();
			pqAB.pop();
		} else {
			ans += pqA.top() + pqB.top();
			pqA.pop(); pqB.pop();
		}
		count++;
	}
	if (count == k) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}