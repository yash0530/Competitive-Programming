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

int n;
const int maxN = 1e5 + 5;
int arr[maxN];

bool poss(int dist) {
	priority_queue<int> pq;
	vector<int> take(n, -1);
	map<int, int> M;
	for (int i = 0; i < n; i++) {
		M[arr[i]]++;
	}
	for (auto m : M) {
		pq.push(m.sc);
	}
	for (int i = 0; i < n; i++) {
		if (take[i] != -1) {
			pq.push(take[i]);
		}
		if (!pq.empty()) {
			int tp = pq.top(); pq.pop();
			if (tp > 1) {
				if ((i + dist + 1) >= n) {
					return false;
				} else {
					take[i + dist + 1] = tp - 1;
				}
			}
		}
	}
	return true;
}

int32_t main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int res = 0;
		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (poss(mid)) {
				res = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}