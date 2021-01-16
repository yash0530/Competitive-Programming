#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()


namespace maxx {

	int *arr, *tree, *lazy;
	int n;

	void build(int nn) {
		n = nn + 1;
		arr = new int[n];
		tree = new int[4 * n];
		lazy = new int[4 * n];
		for (int i = 0; i < n; i++) arr[i] = 0;
		for (int i = 0; i < 4 * n; i++) tree[i] = 0;
		for (int i = 0; i < 4 * n; i++) lazy[i] = 0;
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
	        tree[v] = max(tree[v*2], tree[v*2+1]);
	    }
	}

	int queryMax(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
	    if (l > r)
	        return -1000000;
	    if (l == tl && tr == r) 
	        return tree[v];
	    push(v);
	    int tm = (tl + tr) / 2;
	    return max(queryMax(l, min(r, tm), v*2, tl, tm), queryMax(max(l, tm+1), r, v*2+1, tm+1, tr));
	}
};

namespace minn {

	int *arr, *tree, *lazy;
	int n;

	void build(int nn) {
		n = nn + 1;
		arr = new int[n];
		tree = new int[4 * n];
		lazy = new int[4 * n];
		for (int i = 0; i < n; i++) arr[i] = 0;
		for (int i = 0; i < 4 * n; i++) tree[i] = 0;
		for (int i = 0; i < 4 * n; i++) lazy[i] = 0;
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
	        return 1000000;
	    if (l == tl && tr == r) 
	        return tree[v];
	    push(v);
	    int tm = (tl + tr) / 2;
	    return min(queryMin(l, min(r, tm), v*2, tl, tm), queryMin(max(l, tm+1), r, v*2+1, tm+1, tr));
	}
};


bool intersect(int a, int b, int c, int d) {
	if (min(d, b) >= max(a, c)) return true;
	return false;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		string s; cin >> s;
		int curr = 0;
		vector<int> mins(n + 1), maxs(n + 1), vals(n + 1);
		vector<int> mins_back(n + 1), maxs_back(n + 1);
		for (int i = 1; i <= n; i++) {
			curr -= s[i - 1] == '-';
			curr += s[i - 1] == '+';
			vals[i] = curr;
			maxs[i] = max(maxs[i - 1], curr);
			mins[i] = min(mins[i - 1], curr);
		}

		minn :: build(n);
		maxx :: build(n);

		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '-') {
				maxx :: updateRange(i, n - 1, -1);
				minn :: updateRange(i, n - 1, -1);
				maxs_back[i] = (maxx :: queryMax(i, n - 1));
				mins_back[i] = (minn :: queryMin(i, n - 1));
			} else {
				maxx :: updateRange(i, n - 1, 1);
				minn :: updateRange(i, n - 1, 1);
				maxs_back[i] = (maxx :: queryMax(i, n - 1));
				mins_back[i] = (minn :: queryMin(i, n - 1));
			}
		}
		int l, r;
		while (m--) {
			cin >> l >> r;
			int a1 = mins[l - 1], b1 = maxs[l - 1];
			int fct = vals[l - 1];
			int a2 = mins_back[r] + fct, b2 = maxs_back[r] + fct;
			if (intersect(a1, b1, a2, b2)) {
				cout << max(b1, b2) - min(a1, a2) + 1 << endl;
			} else {
				cout << b1 - a1 + 1 + b2 - a2 + 1 << endl;
			}
		}
	}
	return 0;
}