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

void solve() {
	int n, d; cin >> n >> d;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		cout << d - 1 << endl;
	} else {
		set<int> diff;
		for (auto a : arr) {
			diff.insert(a);
		}
		if (d == 2) {
			if (size(diff) < n) {
				cout << 0 << endl;
			} else {
				cout << 1 << endl;
			}
		} else {
			map<int, int> m;
			int mx = 0;
			for (auto a : arr) {
				m[a]++;
				mx = max(mx, m[a]);
			}
			if (mx >= 3) {
				cout << 0 << endl;
			} else {
				bool big = false;
				for (auto a : arr) {
					if (a % 2 == 0) {
						if (diff.find(a / 2) != diff.end()) {
							big = true;
							break;
						}
					}
				}
				if (big) {
					cout << 1 << endl;
				} else {
					bool found = false;
					for (auto x : m) {
						if (x.sc == 2) {
							if (diff.upper_bound(x.fs) != diff.end()) {
								found = true;
								break;
							}
						}
					}
					if (found) {
						cout << 1 << endl;
					} else {
						cout << 2 << endl;
					}	
				}
			}
		}
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
