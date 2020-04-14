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
		vector<pair<int, int>> arr(2 * n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
			arr[i + n] = arr[i];
		}
		int res = INF;
		int val = arr[0].first;
		int high = 1;
 		for (int low = 0; low < n; low++) {
 			if (low != 0) {
 				val -= arr[low - 1].first;
 				if (arr[low].first > arr[low - 1].second) {
 					val += arr[low - 1].second;
 				} else {
 					val += arr[low].first;
 				}
 			}
 			while (high < (n + low)) {
 				if (arr[high].first > arr[high - 1].second) {
 					val += arr[high].first - arr[high - 1].second;
 				}
 				high++;
 			}
 			res = min(res, val);
 		}
 		cout << res << endl;
 	}
    return 0;
}
