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
#define Mat vector<vector<int>>
#define getMat(aa, bb) vector<vector<int>>(aa, vector<int>(bb, 0))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n % 4 == 0) {
			for (int i = 0; i < n; i += 4) {
				int x = i + 2;
				cout << x << " " << x + 1 << " " << x + 3 << " " << x + 2 << " ";
			} cout << endl;
		} else if (n % 4 == 1) {
			for (int i = 0; i < (n - 1); i += 4) {
				int x = i + 2;
				cout << x << " " << x + 1 << " " << x + 3 << " " << x + 2 << " ";
			} cout << 0 << endl;
		} else if (n % 4 == 2) {
			cout << "4 1 2 12 3 8 ";
			for (int i = 6; i < n; i += 4) {
				int x = i + 8;
				cout << x << " " << x + 1 << " " << x + 3 << " " << x + 2 << " ";
			} cout << endl;
		} else if (n == 3) {
			cout << "2 1 3" << endl;
		} else {
			cout << "4 1 2 12 3 8 0 ";
			for (int i = 7; i < n; i += 4) {
				int x = i + 7;
				cout << x << " " << x + 1 << " " << x + 3 << " " << x + 2 << " ";
			} cout << endl;
		}
	}
	return 0;
}