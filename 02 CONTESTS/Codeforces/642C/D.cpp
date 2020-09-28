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

struct custom { 
    bool operator()(pii const& a, pii const& b) {
    	if ((a.sc - a.fs) == (b.sc - b.fs)) {
    		return a.fs > b.sc;
    	}
    	return (a.sc - a.fs) < (b.sc - b.fs);
    }
};

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		priority_queue<pii, vector<pii>, custom> pq;
		pq.push({ 0, n - 1 });
		vector<int> res(n);
		int curr = 1;
		while (!pq.empty()) {
			pii c = pq.top();
			res[(c.fs + c.sc) / 2] = curr++;
			int left = ((c.fs + c.sc) / 2) - 1;
			int right = ((c.fs + c.sc) / 2) + 1;
			pq.pop();
			if (c.fs <= left) {
				pq.push({ c.fs, left });
			}
			if (c.sc >= right) {
				pq.push({ right, c.sc });
			}
		}
		for (auto r : res) cout << r << " ";
		cout << endl;
	}
	return 0;
}
