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

bool lessThan90(pii a, pii b, pii c) {
	int ux = a.fs - b.fs;
	int vx = c.fs - b.fs;
	int uy = a.sc - b.sc;
	int vy = c.sc - b.sc;
	return ((ux * vx) + (uy * vy)) > 0;
}

signed main() { fastio;
	int n; cin >> n;
	vector<pii> pp(n);
	vector<int> res;
	for (int i = 1; i <= n; i++) res.pb(i);
	for (auto &p : pp) {
		cin >> p.fs >> p.sc;
	}
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int i = 2; i < n; i++) {
			if (!lessThan90(pp[i - 2], pp[i - 1], pp[i])) {
				count++;
				swap(pp[i - 1], pp[i]);
				swap(res[i - 1], res[i]);
			}
		}
		if (count == 0) {
			break;
		}
	}
	for (auto r : res) {
		cout << r << " ";
	} cout << endl;
	return 0;
}