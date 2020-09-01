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

const int maxN = 1e5 + 5;
int n, q;
int tree[4 * maxN], lazy[4 * maxN], arr[maxN], avail[maxN];

void build(int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int queryMax(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return tree[v];
    int tm = (tl + tr) / 2;
    return max(queryMax(l, min(r, tm), v*2, tl, tm), queryMax(max(l, tm+1), r, v*2+1, tm+1, tr));
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n >> q;
		map<int, int> MP;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			MP[arr[i]] = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> avail[i];
		}
		build();
		while (q--) {
			int ty; cin >> ty;
			if (ty == 1) {
				int l, r, val;
				cin >> l >> r >> val;
				int mx = queryMax(l - 1, r - 1);
				int loc = MP[mx];
				avail[loc] += val;
			} else {
				int v, i, qt, thr;
				cin >> v >> i >> qt >> thr;
				int l = max(0LL, i - v - 1);
				int r = min(n - 1, i + v - 1);
				int mx = queryMax(l, r);
				if (mx < thr) {
					cout << "No purchase" << endl;
				} else {
					int loc = MP[mx];
					if (avail[loc] < qt) {
						cout << "No purchase" << endl;
					} else {
						avail[loc] -= qt;
						cout << loc + 1 << endl;
					}
				}
			}
		}
	}
	return 0;
}