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

bool check(vector<int> a) {
    for (int i = 0; i + 1 < size(a); i++) {
        if (a[i] > a[i + 1]) return false;
        a[i + 1] -= a[i];
        a[i] = 0;
    }
    if (a.back() == 0) return true;
    return false;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p(n + 2), s(n + 2), mp(n + 2), ms(n + 2);
		vector<int> arr(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			p[i] = arr[i] - p[i - 1];
			mp[i] = min(mp[i - 1], p[i]);
		}
		for (int i = n; i >= 1; i--) {
			s[i] = arr[i] - s[i + 1];
			ms[i] = min(ms[i + 1], s[i]);
		}
		bool poss = false;
		for (int i = 1; i <= (n - 1); i++) {
			if ((mp[i - 1] >= 0) and (ms[i + 2] >= 0)) {
				if (check({ p[i - 1], arr[i + 1], arr[i], s[i + 2] })) {
					poss = true;
				}
			}
		}
		if (poss or (mp[n] == 0 and p[n] == 0)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}