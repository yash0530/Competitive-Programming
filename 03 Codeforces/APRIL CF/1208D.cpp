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

const int maxN = 2e5 + 5;
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

int findLastZero(int l = 0, int r = n - 1, int v = 1, int tl = 0, int tr = n - 1) {
	if (l == r) return l;
    push(v);
    int tm = (tl + tr) / 2;
    if (tree[2*v+1] == 0)
    	return findLastZero(max(l, tm+1), r, v*2+1, tm+1, tr);
    return findLastZero(l, min(r, tm), v*2, tl, tm);
}

int32_t main() { fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	build();
	vector<int> res(n);
	for (int i = 1; i <= n; i++) {
		int pos = findLastZero();
		updateRange(pos, pos, 1e16);
		updateRange(pos + 1, n - 1, -i);
		res[pos] = i;
	}
	for (auto r : res) {
		cout << r << " ";
	} cout << endl;
	return 0;
}