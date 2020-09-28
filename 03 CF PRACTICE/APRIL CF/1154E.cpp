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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	priority_queue<pair<int, int>> pq;
	set<int> locs, locs_neg;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push({ arr[i], i});
		locs.insert(i);
		locs_neg.insert(-i);
	}
	vector<int> res(n, -1);
	int curr = 1;
	while (!pq.empty()) {
		int loc = pq.top().second;
		pq.pop();
		if (res[loc] == -1) {
			locs.erase(loc);
			locs_neg.erase(-loc);
			res[loc] = curr;
			int right = loc, count = 0;
			while (count < k) {
				auto next = locs.upper_bound(right);
				if (next == locs.end()) {
					break;
				}
				right = *next;
				res[right] = curr;
				locs.erase(right);
				locs_neg.erase(-right);
				count++;
			}
			int left = loc; count = 0;
			while (count < k) {
				auto next = locs_neg.upper_bound(-left);
				if (next == locs_neg.end()) {
					break;
				}
				left = -1 * (*next);
				res[left] = curr;
				locs.erase(left);
				locs_neg.erase(-left);
				count++;
			}
			if (curr == 1) curr = 2;
			else curr = 1;
		}
	}
	for (auto r : res) {
		cout << r;
	} cout << endl;
    return 0;
}
