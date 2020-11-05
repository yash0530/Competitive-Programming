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
	int n, m; cin >> n >> m;
	string x, y;
	map<string, string> chef_country;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		chef_country[x] = y;
	}
	map<string, int> country_freq;
	map<string, int> chef_freq;
	for (int i = 0; i < m; i++) {
		cin >> x;
		chef_freq[x]++;
		country_freq[chef_country[x]]++;
	}
	int mx = 0;
	for (auto cf : country_freq) {
		if (cf.sc > mx) {
			mx = cf.sc; x = cf.fs;
		}
	} cout << x << endl;
	mx = 0;
	for (auto cf : chef_freq) {
		if (cf.sc > mx) {
			mx = cf.sc; x = cf.fs;
		}
	} cout << x << endl;
	return 0;
}