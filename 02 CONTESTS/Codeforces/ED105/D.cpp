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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

int val[2000];
vector<int> adj[2000];
int k;
int mat[501][501];

void build(vector<int> arr) {
	int n = size(arr);
	int mx = 0;
	for (auto x : arr) {
		mx = max(mx, mat[arr[0]][x]);
	}

	int here = k++;
	val[here] = mx;

	vector<int> groups(n, -1);
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (groups[i] == -1) {
			curr++;
			groups[i] = curr;
			for (int j = 0; j < n; j++) {
				if (groups[j] == -1) {
					if (mat[arr[i]][arr[j]] != mx) {
						groups[j] = curr;
					}
				}
			}	
		}
	}

	for (int gg = 1; gg <= n; gg++) {
		vector<int> curr;
		for (int i = 0; i < n; i++) {
			if (groups[i] == gg) {
				curr.pb(arr[i]);
			}
		}
		if (size(curr)) {
			if (size(curr) > 1) {
				adj[here].pb(k);
				build(curr);
			} else {
				adj[here].pb(curr[0]);
			}
		} else {
			return;
		}
	}
}

signed main() { fastio;
	cin >> k;
	vector<int> arr;
	for (int i = 1; i <= k; i++) {
		arr.pb(i);
		for (int j = 1; j <= k; j++) {
			cin >> mat[i][j];
			if (i == j) val[i] = mat[i][j];
		}
	}
	k++;
	build(arr);
	k--;
	cout << k << endl;
	for (int i = 1; i <= k; i++) {
		cout << val[i] << " ";
	} cout << endl;
	cout << size(arr) + 1 << endl;
	for (int i = 1; i <= k; i++) {
		for (auto j : adj[i]) {
			cout << j << " " << i << endl;
		}
	}
	return 0;
}