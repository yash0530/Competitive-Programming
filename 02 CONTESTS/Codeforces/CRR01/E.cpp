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

int getVal(int val, int bk) {
	int rem = val % bk;
	int okay = val / bk;
	int ans = (bk - rem) * okay * okay;
	ans += rem * (okay + 1) * (okay + 1);
	return ans;
}

int32_t main() { fastio;
	int n, k, x;
	cin >> n >> k;
	// what poss val diff can I achieve
	// what is my current val
	// how many times have I divided it
	priority_queue<array<int, 3>> pq;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1) {
			pq.push({ 0, 1, 1 });
		} else {
			pq.push({ getVal(x, 1) - getVal(x, 2), x, 1 });
		}
	}
	int count = n;
	while (count < k) {
		count++;
		auto x = pq.top(); pq.pop();
		pq.push({ getVal(x[1], x[2] + 1) - getVal(x[1], x[2] + 2), x[1], x[2] + 1 });
	}
	int ans = 0;
	while (!pq.empty()) {
		auto x = pq.top(); pq.pop();
		ans += getVal(x[1], x[2]);
	}
	cout << ans << endl;
	return 0;
}