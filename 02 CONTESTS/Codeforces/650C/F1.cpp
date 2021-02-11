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

void cocomp(vector<int> &arr) {
    vector<int> compress;
    int nn = size(arr);
    for (int i = 0; i < nn; i++) {
        compress.pb(arr[i]);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for (int i = 0; i < nn; i++) arr[i] = lower_bound(compress.begin(), compress.end(), arr[i]) - compress.begin();
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		cocomp(arr);
		map<int, int> okay;
		for (auto x : arr) {
			if (okay.find(x - 1) != okay.end()) {
				okay[x] = okay[x - 1] + 1;
			} else {
				okay[x] = 1;
			}
		}
		int mx = 0;
		for (auto m : okay) {
			mx = max(m.sc, mx);
		}
		cout << n - mx << endl;
	}
	return 0;
}