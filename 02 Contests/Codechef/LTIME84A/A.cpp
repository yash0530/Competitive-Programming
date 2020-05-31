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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string a, b;
		cin >> a >> b;
		vector<vector<int>> freqA(128);
		vector<vector<int>> freqB(128);
		for (int i = 0; i < n; i++) {
			freqA[a[i]].pb(i);
			freqB[b[i]].pb(i);
		}
		bool poss = true;
		for (int i = 0; i < n; i++) {
			if (b[i] > a[i]) {
				poss = false;
				break;
			}
		}
		if (!poss) {
			cout << -1 << endl;
			continue;
		}
		vector<vector<int>> res;
		for (char i = 'z'; i >= 'a'; i--) {
			if (size(freqB[i])) {
				if (!size(freqA[i])) {
					poss = false;
				}
				if (freqA[i] == freqB[i]) continue;
				vector<int> diff;
				set_difference(freqB[i].begin(), freqB[i].end(), freqA[i].begin(), freqA[i].end(), back_inserter(diff));
				if (!size(diff)) continue;
				vector<int> add;
				set_union(freqA[i].begin(), freqA[i].end(), freqB[i].begin(), freqB[i].end(), back_inserter(add));
				res.pb(add);
			}
		}
		if (!poss) cout << -1 << endl;
		else {
			cout << size(res) << endl;
			for (auto r : res) {
				cout << size(r) << " ";
				for (auto x : r) cout << x << " ";
				cout << endl;
			}
		}
	}
	return 0;
}
