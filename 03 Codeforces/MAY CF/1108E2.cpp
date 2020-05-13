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

const int maxN = 1e5 + 5;
int n;
int tree[4 * maxN], lazy[4 * maxN], arr[maxN];

void build(int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}

void push(int v) {
    tree[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void updateRange(int l, int r, int addend, int v = 1, int tl = 0, int tr = n - 1) {
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
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}

int queryMin(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return INF;
    if (l <= tl && tr <= r)
        return tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(queryMin(l, min(r, tm), v*2, tl, tm), queryMin(max(l, tm+1), r, v*2+1, tm+1, tr));
}

int32_t main() { fastio;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	build();
	vector<pii> segs(m);
	map<int, vector<int>> starts, ends;
	for (int i = 0; i < m; i++) {
		cin >> segs[i].fs >> segs[i].sc;
		segs[i].fs--; segs[i].sc--;
		updateRange(segs[i].fs, segs[i].sc, -1);
		starts[segs[i].fs].pb(i);
		ends[segs[i].sc].pb(i);
	}
	int ans = 0;
	set<int> res, final;
	for (int i = 0; i < m; i++) res.insert(i);
	for (int i = 0; i < n; i++) {
		for (auto x : starts[i]) {
			res.erase(x);
			updateRange(segs[x].fs, segs[x].sc, 1);
		}
		int curr = arr[i] - queryMin(0, n - 1);
		if (curr > ans) {
			ans = curr;
			final = res;
		}
		for (auto x : ends[i]) {
			res.insert(x);
			updateRange(segs[x].fs, segs[x].sc, -1);
		}
	}
	cout << ans << endl;
	cout << size(final) << endl;
	for (auto f : final) cout << f + 1 << " ";
	cout << endl;
	return 0;
}
