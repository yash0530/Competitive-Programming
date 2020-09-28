#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debb(a) cerr << #a << en; cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n; cin >> n;
	string s; cin >> s;
	pii mono, bi;
	int tcount = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?') {
			mono.sc += 9;
			tcount++;
		} else {
			mono.fs += s[i] - '0';
			mono.sc += s[i] - '0';
		}
	}
	int count = 0;
	for (int i = n / 2; i < n; i++) {
		if (s[i] == '?') {
			bi.sc += 9;
			tcount++;
			count++;
		} else {
			bi.fs += s[i] - '0';
			bi.sc += s[i] - '0';
		}
	}
	if (count * 2 > tcount) {
		int offset = (count - (tcount / 2)) * 9;
		bi.fs += offset;
		bi.sc -= offset;
	} else {
		int offset = ((tcount / 2) - count) * 9;
		bi.fs -= offset;
		bi.sc += offset;
	}
	if (mono.fs >= bi.fs and mono.sc <= bi.sc) {
		cout << "Bicarp" << endl;
	} else {
		cout << "Monocarp" << endl;
	}
	return 0;
}
