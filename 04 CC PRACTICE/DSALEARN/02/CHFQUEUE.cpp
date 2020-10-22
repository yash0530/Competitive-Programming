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

const int maxN = 1e6 + 5;
int n = 1e6 + 5;
int tree[4 * maxN], arr[maxN];

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

// sum over range
int qmin(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r) return INF;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return min(qmin(l, min(r, tm), v*2, tl, tm), qmin(max(l, tm+1), r, v*2+1, tm+1, tr));
}

// update a loc
void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}


int32_t main() { fastio;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < maxN; i++) arr[i] = INF;
	build();
	vector<int> temp(n);
	for (auto &a : temp) cin >> a;
	int res = 1;
	for (int i = n - 1; i >= 0; i--) {
		int q = qmin(0, temp[i] - 1);
		if (q != INF) {
			res = mul(res, q - i + 1);
		}
		update(temp[i], i);
	}
	cout << res << endl;
	return 0;
}