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

const int maxN = 1e5 + 5;
int n;
int tree[4 * maxN], arr[maxN];

void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = new_val;
        arr[pos] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}

int get_first(int x, int v = 1, int lv = 0, int rv = n - 1, int l = 0, int r = n - 1) {
    if(lv > r || rv < l) return maxN;
    if(l <= lv && rv <= r) {
        if (tree[v] > x) return maxN;
        while (lv != rv) {
            int mid = lv + (rv-lv)/2;
            if (tree[2*v] <= x) {
                v = 2*v;
                rv = mid;
            } else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}

int32_t main() { fastio;
	n = maxN; int N; cin >> N;
	vector<int> elems(N);
	for (auto &a : elems) {
		cin >> a;
	}
	memset(arr, -1, sizeof arr);
	memset(tree, -1, sizeof tree);
	update(0, INF);
	set<int> okays;
	for (int i = 0; i < N; i++) {
		int prev = arr[elems[i]];
		update(elems[i], i);
		int val = get_first(prev);
		okays.insert(val);
		if (elems[i] != 1 and val > elems[i]) {
			okays.insert(elems[i]);
		}
	}
	reverse(_all(elems));
	memset(arr, -1, sizeof arr);
	memset(tree, -1, sizeof tree);
	update(0, INF);
	for (int i = 0; i < N; i++) {
		int prev = arr[elems[i]];
		update(elems[i], i);
		int val = get_first(prev);
		okays.insert(val);
		if (elems[i] != 1 and val > elems[i]) {
			okays.insert(elems[i]);
		}
	}
	if (*max_element(_all(elems)) > 1) okays.insert(1);
	int prev = 0;
	for (auto x : okays) {
		if (prev + 1 == x) prev++;
		else {
			cout << prev + 1 << endl;
			exit(0);
		}
	}
	cout << *okays.rbegin() + 1 << endl;
	return 0;
}