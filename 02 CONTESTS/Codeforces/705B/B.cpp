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

vector<int> vals = {
	0, 1, 5, -1, -1, 2, -1, -1, 8, -1
};

bool poss(int a, int b) {
	if (vals[a % 10] == -1 or vals[a / 10] == -1) return false;
	if (vals[b % 10] == -1 or vals[b / 10] == -1) return false;
	return true;
}

string convert(int a, int b) {
	string res;
	res.pb(a / 10 + '0');
	res.pb(a % 10 + '0');
	res.pb(':');
	res.pb(b / 10 + '0');
	res.pb(b % 10 + '0');
	return res;
}

int get(int a) {
	return vals[(a % 10)] * 10 + vals[a / 10];
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int h, m; cin >> h >> m;
		string s; cin >> s;
		array<int, 2> digs = { (s[0] - '0') * 10 +  s[1] - '0', (s[3] - '0') * 10 + s[4] - '0' };
		while (true) {
			if (digs[1] == m) {
				digs[1] = 0;
				digs[0]++;
			}
			if (digs[0] == h) {
				digs[0] = 0;
				digs[1] = 0;
			}
			int a = digs[0], b = digs[1];
			if (poss(a, b)) {
				int c = get(a);
				int d = get(b);
				if ((d < h) and (c < m)) {
					cout << convert(a, b) << endl;
					break;	
				}
			}
			digs[1]++;
		}
	}
	return 0;
}