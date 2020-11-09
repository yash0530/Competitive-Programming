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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		vector<array<int, 3>> okays;
		okays.pb({ s[0], 0, 1 });
		for (int i = 1; i < n; i++) {
			if (s[i] == okays.back()[0]) {
				okays[size(okays) - 1][2]++;
			} else {
				okays.pb({ s[i], i, 1 });
			}
		}
		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
		for (auto o : okays) {
			if (o[0] == 'L') {
				if (o[1] == 0 or (o[1] + o[2] == n))
					pq.push({ 1, o[2], o[1] });
				else
					pq.push({ 0, o[2], o[1] });
			}
		}
		while (!pq.empty()) {
			auto x = pq.top(); pq.pop();
			if (x[2] == 0) {
				for (int i = x[1] - 1; i >= 0; i--) {
					if (k) {
						s[i] = 'W'; k--;
					}
				}
			} else {
				for (int i = x[2], j = 0; j < x[1]; j++, i++) {
					if (k) {
						s[i] = 'W'; k--;
					}
				}	
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!i and s[i] == 'W') ans++;
			else if (i) {
				if (s[i] == 'W' and s[i - 1] == 'W') ans += 2;
				else if (s[i] == 'W' and s[i - 1] == 'L') ans++;
			}
		}
		cout << ans << endl;	
	}
	return 0;
}