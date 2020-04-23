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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		string s, r;
		cin >> s >> r;
		int n = size(s);
		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (s[i] != r[i]) {
				pos.pb(i);
			}
		}
		if (size(pos) == 0) {
			cout << 0 << endl;
		} else if (size(pos) == 1) {
			cout << 1 << endl;
		} else {
			int res = size(pos) * size(pos);
			int left = size(pos), right = size(pos);
			priority_queue<int, vector<int>, greater<int>> pq;
			for (int i = 1; i < size(pos); i++) {
				pq.push(pos[i] - pos[i - 1] - 1);
			}
			while (!pq.empty()) {
				left += pq.top(); pq.pop();
				right--;
				res = min(res, left * right);
			}
			cout << res << endl;
		}
	}
	return 0;
}