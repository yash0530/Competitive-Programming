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

int32_t main() { fastio;
	string s; cin >> s;
	int n = size(s);
	reverse(s.begin(), s.end());
	int okay = 0;
	for (auto x : s) {
		okay += (x - '0');
	}
	int sum = 0, ans = 0, base = 1, diff = 0;
	for (int i = 0; i < n; i++) {
		int val = s[i] - '0';
		diff = (diff + mul(val, base)) % HELL;
		ans = (ans + mul(mul(((n - i) * (n - i - 1)) / 2, val), base)) % HELL;
		okay -= (val);
		sum = (sum + mul(val, base)) % HELL;
		sum = (sum + mul(mul(okay, i + 1), base)) % HELL;
		base = mul(base, 10);
	}
	cout << (sum + ans - diff + HELL) % HELL << endl;
	return 0;
}