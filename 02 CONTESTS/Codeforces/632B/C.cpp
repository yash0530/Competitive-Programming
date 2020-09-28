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
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map<int, int> H;
	H[0] = -1;
	int last_zero = -1;
	int pref = 0, res = 0;
	for (int i = 0; i < n; i++) {
		pref += arr[i];
		if (arr[i] == 0) {
			last_zero = i;
		} else if (H.find(pref) != H.end()) {
			res += min((i - H[pref]) - 1, i - last_zero);
			last_zero = max(last_zero, H[pref] + 1);
		} else {
			res += i - last_zero;
		}
		H[pref] = i;
	}
	cout << res << endl;
    return 0;
}
