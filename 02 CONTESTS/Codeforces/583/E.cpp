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
	int n; cin >> n;
	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].fs;
		arr[i].sc = i + 1;
	}
	sort(arr.begin(), arr.end(), greater<pii>());
	vector<int> path; path.pb(arr[0].sc * 2 - 1);
	for (int i = 1; i < n; i++) {
		cout << arr[i].sc * 2 - 1 << " " << arr[i - 1].sc * 2 - 1 << endl;
		path.pb(arr[i].sc * 2 - 1);
	}
	for (int i = 0; i < n; i++) {
		int loc = i + arr[i].fs - 1;
		if (loc == size(path) - 1) {
			path.pb(arr[i].sc * 2);
		}
		cout << arr[i].sc * 2 << " " << path[loc] << endl;
	}
	return 0;
}
