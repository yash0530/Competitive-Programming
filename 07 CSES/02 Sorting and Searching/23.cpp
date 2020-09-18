// CSES Array Division
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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	int low = 0, high = 1e15, res = INF;
	while (low <= high) {
		int mid = (low + high) / 2;
		bool poss = true; int count = 1, sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) {
				poss = false;
			}
			if ((sum + arr[i]) <= mid) {
				sum += arr[i];
			} else {
				sum = arr[i];
				count++;
			}
		}
		if (poss and (count <= k)) {
			res = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << res << endl;
	return 0;
}