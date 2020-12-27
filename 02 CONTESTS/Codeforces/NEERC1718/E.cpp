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

int n;
const int maxN = 3e5 + 5;
vector<int> only_directed[maxN];
vector<int> max_[maxN];
vector<int> min_[maxN];
vector<pii> edges;
map<pair<int, int>, vector<int>> edges_max;
set<int> verts;
char res_max[maxN];

void dfs(int s) {
	verts.insert(s);
	for (auto x : only_directed[s]) {
		if (verts.find(x) == verts.end()) {
			dfs(x);
		}
	}
}

bool viss[maxN];
int max_ans, min_ans;
void count_max(int s) {
	viss[s] = true;
	max_ans++;
	for (auto x : max_[s]) {
		if (!viss[x]) {
			for (auto lc : edges_max[{ s, x }]) {
				res_max[lc] = '+';
			}
			for (auto lc : edges_max[{ x, s }]) {
				res_max[lc] = '-';
			}
			count_max(x);
		}
	}
}

void count_min(int s) {
	viss[s] = true;
	min_ans++;
	for (auto x : min_[s]) {
		if (!viss[x]) {
			count_min(x);
		}
	}
}

signed main() { fastio;
	int n, m, s, t, u, v;
	cin >> n >> m >> s;
	int loc = 0;
	for (int i = 0; i < m; i++) {
		cin >> t >> u >> v;
		if (t == 1) {
			only_directed[u].pb(v);
			max_[u].pb(v);			
			min_[u].pb(v);
		} else {
			edges.pb({ u, v });
			edges_max[{ u, v }].pb(loc++);
			max_[u].pb(v);
			max_[v].pb(u);
		}
	}

	dfs(s);
	count_max(s);
	cout << max_ans << endl;
	for (int i = 0; i < loc; i++) {
		if (res_max[i]) cout << res_max[i];
		else cout << '-';
	} cout << endl;

	vector<char> res;
	for (auto e : edges) {
		if (verts.find(e.fs) != verts.end()) {
			res.pb('-');
			min_[e.sc].pb(e.fs);
		} else {
			res.pb('+');
			min_[e.fs].pb(e.sc);
		}
	}
	
	memset(viss, 0, sizeof viss);
	count_min(s);
	cout << min_ans << endl;
	for (auto r : res) {
		cout << r;
	} cout << endl;
	return 0;
}