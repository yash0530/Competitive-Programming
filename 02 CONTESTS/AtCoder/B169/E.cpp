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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
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
	vector<pii> arr(n);
	vector<pii> events;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].fs >> arr[i].sc;
		events.pb({ arr[i].fs, 1 });
		events.pb({ arr[i].sc, 2 });
	}
	sort(events.begin(), events.end());
	int res = 0;
	if (n & 1) {
		int ins = (n + 1) / 2;
		int start = -1, stop = -1;
		int curr = 0, rem = 0;
		for (auto e : events) {
			if (e.sc == 1) {
				curr++;
			} else {
				rem++;
			}
			if (start == -1 and curr == ins) {
				start = e.fs;
			}
			if (stop == -1 and rem == ins) {
				stop = e.fs;
			}
		}
		res = stop - start + 1;
	} else {
		int ins = n / 2;
		int curr = 0, rem = 0;
		int astart = -1, astop = -1, bstart = -1, bstop = -1;
		for (auto e : events) {
			if (e.sc == 1) {
				curr++;
			} else {
				rem++;
			}
			if (astart == -1 and curr == ins) {
				astart = e.fs;
			}
			if (bstart == -1 and curr == (ins + 1)) {
				bstart = e.fs;
			}
			if (astop == -1 and rem == ins) {
				astop = e.fs;
			}
			if (bstop == -1 and rem == (ins + 1)) {
				bstop = e.fs;
			}
		}
		res = bstop - bstart + 1 + astop - astart;
	}
	cout << res << endl;
	return 0;
}
