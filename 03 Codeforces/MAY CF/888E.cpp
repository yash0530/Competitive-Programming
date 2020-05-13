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

int n, m;
vector<int> sums;
int best;

void getSums(vector<int> &arr, int max, int curr, int sum) {
	if (curr == max) {
		sums.pb(sum % m);
		return;
	}
	getSums(arr, max, curr + 1, sum);
	sum += arr[curr];
	getSums(arr, max, curr + 1, sum);
}

void getBest(vector<int> &arr, int maxi, int curr, int sum) {
	if (curr == maxi) {
		sum = sum % m;
		int val = m - (sum + 1);
		auto loc = upper_bound(sums.begin(), sums.end(), val);
		if (loc != sums.begin()) {
			loc--;
			sum = sum + *loc;
		}
		best = max(best, sum);
		return;
	}
	getBest(arr, maxi, curr + 1, sum);
	sum += arr[curr];
	getBest(arr, maxi, curr + 1, sum);
}

int32_t main() { fastio;
	cin >> n >> m;
	if (n == 1) {
		int x; cin >> x;
		cout << x % m << endl;
	} else {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		getSums(arr, n / 2, 0, 0);
		sort(sums.begin(), sums.end());
		getBest(arr, n, n / 2, 0);
		cout << best << endl;
	}
	return 0;
}
