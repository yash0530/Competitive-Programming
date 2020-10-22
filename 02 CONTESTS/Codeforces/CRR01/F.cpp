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

// histogram approach explained in the editorial
int32_t main() { fastio;
	int n; cin >> n;
	string s; cin >> s;
	s.pb('0');
	vector<vector<int>> pos(n + 5);
	for (int i = 0; i <= n; i++) {
		if (i and s[i] == '0' and s[i - 1] == '1') {
			int loc = i - 1, val = 1;
			while (loc >= 0 and s[loc] == '1') {
				pos[val].pb(loc);
				val++; loc--;
			}
		}
	}
	s.pop_back();

	int curr = 0, ans = 0, sum = 0, loc = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			curr = 0;
			ans += sum;
			loc = i;
		} else {
			curr++;
			if (pos[curr].empty()) {
				sum += i + 1;
			} else {
				auto x = lower_bound(pos[curr].begin(), pos[curr].end(), loc);
				if (x == pos[curr].begin()) {
					sum += i + 1;
				} else {
					x--;
					sum += (i - *x);
				}
			}
			ans += sum;
		}
	}
	cout << ans << endl;
	return 0;
}