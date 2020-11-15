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
                      
signed main() { fastio;
	vector<int> arr(6);
	for (auto &a : arr) cin >> a;
	int n, x; cin >> n; 
	vector<array<int, 6>> okay(n);
	for (auto &o : okay) {
		cin >> x;
		for (int i = 0; i < 6; i++) {
			o[i] = x - arr[i];
		}
	}
	vector<pii> pairs;
	for (int i = 0; i < n; i++) {
		for (auto x : okay[i]) {
			pairs.pb({ x, i });
		}
	}
	sort(pairs.begin(), pairs.end());
	vector<int> freq(n + 5);
	int count = 0, ans = INF;
	int SZ = size(pairs);
	int low = 0, high = 0;
	multiset<int> vals;
	while (high < SZ) {
		freq[pairs[high].sc]++;
		vals.insert(pairs[high].fs);
		if (freq[pairs[high++].sc] == 1) count++;
		if (count == n) {
			while (low < high) {
				ans = min(ans, *vals.rbegin() - *vals.begin());
				vals.erase(vals.find(pairs[low].fs));
				freq[pairs[low].sc]--;
				if (freq[pairs[low++].sc] == 0) {
					count--;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}