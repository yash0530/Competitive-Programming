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

const int maxN = 5e5 + 5;
int n;
int tree[4 * maxN], lazy[4 * maxN], arr[maxN];

void build(int v = 1, int tl = 0, int tr = maxN - 1) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

void push(int v) {
    tree[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void updateRange(int l, int r, int addend, int v = 1, int tl = 0, int tr = maxN - 1) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        updateRange(l, min(r, tm), addend, v*2, tl, tm);
        updateRange(max(l, tm+1), r, addend, v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int queryMax(int l, int r, int v = 1, int tl = 0, int tr = maxN - 2) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(queryMax(l, min(r, tm), v*2, tl, tm), queryMax(max(l, tm+1), r, v*2+1, tm+1, tr));
}
int toLoc(int r, int c) {
	return ((r - 1) * (1e5 + 2)) + c;
}

int32_t main() { fastio;
	int q;
	cin >> n >> q;
	int r, c;
	set<pii> s;
	build();
	while (q--) {
		cin >> r >> c;
		if (s.find({ r, c }) == s.end()) {
			s.insert({ r, c });
			updateRange(toLoc(r, c), toLoc(r, c), 1000);
			if (r == 1) {
				updateRange(toLoc(r + 1, c), toLoc(r + 1, c), 1);
				if (c > 1) {
					updateRange(toLoc(r + 1, c - 1), toLoc(r + 1, c - 1), 1);
				}
				if (c < n) {
					updateRange(toLoc(r + 1, c + 1), toLoc(r + 1, c + 1), 1);
				}
			} else {
				updateRange(toLoc(r - 1, c), toLoc(r - 1, c), 1);
				if (c > 1) {
					updateRange(toLoc(r - 1, c - 1), toLoc(r - 1, c - 1), 1);
				}
				if (c < n) {
					updateRange(toLoc(r - 1, c + 1), toLoc(r - 1, c + 1), 1);
				}
			}
		} else {
			s.erase({ r, c });
			updateRange(toLoc(r, c), toLoc(r, c), -1000);
			if (r == 1) {
				updateRange(toLoc(r + 1, c), toLoc(r + 1, c), -1);
				if (c > 1) {
					updateRange(toLoc(r + 1, c - 1), toLoc(r + 1, c - 1), -1);
				}
				if (c < n) {
					updateRange(toLoc(r + 1, c + 1), toLoc(r + 1, c + 1), -1);
				}
			} else {
				updateRange(toLoc(r - 1, c), toLoc(r - 1, c), -1);
				if (c > 1) {
					updateRange(toLoc(r - 1, c - 1), toLoc(r - 1, c - 1), -1);
				}
				if (c < n) {
					updateRange(toLoc(r - 1, c + 1), toLoc(r - 1, c + 1), -1);
				}
			}
		}
		if (queryMax(0, maxN - 1) > 1000) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}
