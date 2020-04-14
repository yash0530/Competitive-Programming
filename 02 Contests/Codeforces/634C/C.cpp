#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)
#define size(a) (int) a.size()

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int max_poss = n / 2;
		map<int, int> H;
		for (auto a : arr) {
			H[a]++;
		}
		int mx = 0;
		for (auto h : H) {
			mx = max(h.second, mx);
		}
		max_poss = min(max_poss, mx);
		bool all_used = false;
		if (max_poss == mx) {
			all_used = true;
		}
		int x = size(H);
		if (!all_used) {
			cout << min(x, max_poss) << endl;
		} else {
			int mx2 = size(H) - 1;
			if (mx2 < (max_poss - 1)) {
				cout << mx2 + 1 << endl;
			} else {
				cout << min(mx2, max_poss) << endl;
			}
		}
	}	    
    return 0;
}
