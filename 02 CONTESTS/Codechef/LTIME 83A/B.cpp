#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
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

int n;
const int maxN = 2e6 + 5;
int tree[maxN];

void update(int index, int val) {
    while (index <= n) {
        tree[index] += val;
        index += (index & -index);
    }
}

int read(int index) {
    int sum = 0;
    while (index) {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

int32_t main() { fastio;
	int t; cin >> t;
	n = maxN;
	while (t--) {
		int n, q, u, v;
		cin >> n >> q;

		vector<vector<int>> events;
		for (int i = 0; i < n; i++) {
			cin >> u >> v;
			events.pb({ u + v, 1, u - v });
		}

		for (int i = 0; i < q; i++) {
			cin >> u >> v;
			events.pb({ v, 3, u, i });
		}
		sort(events.begin(), events.end());

		vector<int> updates;
		vector<int> res(q); int count = 0;
		for (auto e : events) {
			if (e[1] == 1) {
				count++;
				update(e[2] + 1000002, 1);
				updates.push_back(e[2] + 1000002);
			} else {
				res[e[3]] = count - read(e[2] + 1000001);
			}
		}
		for (auto r : res) {
			cout << r << " ";
		} cout << endl;

		for (auto u : updates) {
			update(u, -1);
		}
	}
	return 0;
}
