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
#define deba(x) cerr << #x << en; for (auto y : x) cerr << y << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define mulp(a, b, p) ((a % p) * (b % p)) % p

int32_t main() { fastio;
	int n, p;
	cin >> n >> p;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<int> res;
	for (int i = arr[0]; i <= arr.back(); i++) {
		int x = i;
		bool yes = true;
		for (auto a : arr) {
			if (a > x) yes = false;
			x++;
		}
		if (yes) {
			int times = 1;
			vector<int> another;
			for (int j = 0; j < n; j++) {
				another.pb(i + j);
			}
			vector<int> th;
			int a = 0, b = 0;
			while (a < n) {
				while (arr[a] > another[b]) b++;
				th.pb(n - b);
				a++;
			}
			for (int j = (n - 1), _ = 0; j >= 0; j--, _++) {
				times = mulp(times, (th[j] - _), p);
			}
			if (times) {
				res.pb(i);
			}
		}
	}
	cout << size(res) << endl;
	for (auto r : res) {
		cout << r << " ";
	} cout << endl;
	return 0;
}