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
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<pii> segs(m);
	for (int i = 0; i < m; i++) {
		cin >> segs[i].fs >> segs[i].sc;
		segs[i].fs--; segs[i].sc--;
	}
	int ans = 0;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		vector<int> temp_res;
		vector<int> temp = arr;
		for (int j = 0; j < m; j++) {
			if (!(segs[j].fs <= i and i <= segs[j].sc)) {
				for (int k = segs[j].fs; k <= segs[j].sc; k++) {
					temp[k]--;
				}
				temp_res.pb(j);
			}
		}
		int mn = *min_element(temp.begin(), temp.end());
		if ((arr[i] - mn) > ans) {
			ans = arr[i] - mn;
			res = temp_res;
		}
	}
	cout << ans << endl;
	cout << size(res) << endl;
	for (auto r : res) cout << r + 1 << " ";
	cout << endl;
	return 0;
}
