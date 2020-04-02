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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int n;
const int maxN = 3e5 + 5;
int p[maxN], q[maxN], idx[maxN], res[maxN], tree[4 * maxN], lazy[4 * maxN];

void push(int v) {
    tree[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int32_t main() { fastio;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> p[i];
    	idx[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
    	cin >> q[i];
    }

    res[1] = n;
    int ans = n;
    update(1, 1, n, 1, idx[ans], 1);
    for (int i = 2; i <= n; i++) {
    	update(1, 1, n, 1, q[i - 1], -1);
    	int mx = query(1, 1, n, 1, n);
    	while (mx <= 0 and ans >= 1) {
			ans--;
    		update(1, 1, n, 1, idx[ans], 1);
    		mx = query(1, 1, n, 1, n);
    	}
    	res[i] = ans;
    }

    for (int i = 1; i <= n; i++) {
    	cout << res[i] << " ";
    }

    return 0;
}