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

int n, m;
const int maxN = 3e5 + 5;
int arr[maxN];

bool poss(int x) {
	int prev = 0;
	for (int i = 0; i < n; i++) {
		int l1 = arr[i];
		int h1 = min(m - 1, arr[i] + x);
		if ((arr[i] + x) >= m) {
			int h2 = (arr[i] + x) % m;
			if (h2 >= prev) {
				continue;
			}
		}
		if (h1 >= prev) {
			prev = max(prev, l1);
		} else {
			return false;
		}
	}
	return true;
}

int32_t main() { fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int res = -1;
	int low = 0, high = m - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (poss(mid)) {
			res = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << res << endl;
    return 0;
}
