#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e12
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
pii tree[4 * maxN]; int lazy[4 * maxN], arr[maxN];

// ----------------- STANDARD SEG TREE NO LAZY --------------------------- //

void build(int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = { arr[tl], tl };
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}

void push(int v) {
    tree[v*2].fs += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1].fs += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void updateRange(int l, int r, int addend, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v].fs += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        updateRange(l, min(r, tm), addend, v*2, tl, tm);
        updateRange(max(l, tm+1), r, addend, v*2+1, tm+1, tr);
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}

pii queryMin(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return { INF, 0 };
    if (l <= tl && tr <= r)
        return tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(queryMin(l, min(r, tm), v*2, tl, tm), queryMin(max(l, tm+1), r, v*2+1, tm+1, tr));
}

int32_t main() { fastio;
	arr[maxN - 1] = INF;
	cin >> n;
	vector<int> ax(n);
	for (int i = 0; i < n; i++) {
		cin >> ax[i];
	}
	vector<int> costs(n);
	for (int i = 0; i < n; i++) {
		cin >> costs[i];
	}
	map<int, vector<int>> M;
	for (int i = 0; i < n; i++) {
		M[ax[i]].pb(costs[i]);
	}
	vector<pii> okay;
	int prev = 0, loc = 0;
	for (auto x : M) {
		prev += size(x.sc);
		okay.pb({ x.fs, prev });
		for (auto y : x.sc) {
			arr[loc++] = y;
		}
	}
	vector<int> og;
	for (int i = 0; i < n; i++) {
		og.pb(arr[i]);
	}
	build();
	int ans = 0, have = 0, prev = 0;
	for (int i = 0; i < n - 1; i++) {
		prev += okay[i].sc;
		have += okay[i + 1].fs - okay[i].fs;
		have--;
		pii curr_min = queryMin(0, prev - 1);
		ans += curr_min.fs;
		updateRange(curr_min.sc, curr_min.sc, INF);
		int rm = min(have, okay[i + 1].fs - okay[i].fs - 1);
		while (rm) {
			pii curr = queryMin(0, prev - 1);
			ans += curr.fs + og[curr.sc] * rm;
			updateRange(curr.sc, curr.sc, INF);
			rm--;
		}
	}
	cout << ans << endl;
	return 0;
}
