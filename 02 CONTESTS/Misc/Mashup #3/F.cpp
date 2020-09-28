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

bool equal(vector<int> &a, vector<int> &b) {
	if (size(a) != size(b)) {
		return false;
	}
	for (int i = 0; i < size(a); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int32_t main() { fastio;
	int n; cin >> n;
	int total = n * (n - 1) / 2;
	vector<vector<int>> unions;
	map<int, vector<int>> H;
	for (int i = 0; i < total; i++) {
		int x; cin >> x;
		vector<int> v(x);
		for (int j = 0; j < x; j++) {
			cin >> v[j];
		}
		unions.pb(v);
		for (auto u : unions[i]) {
			H[u].pb(i);
		}
	}
	vector<int> visited(2000);
	vector<vector<int>> res;
	for (auto u : unions) {
		for (int i = 0; i < size(u); i++) {
			if (!visited[u[i]]) {
				visited[u[i]] = true;
				vector<int> my = H[u[i]];
				vector<int> add = { u[i] };
				for (auto x : u) {
					if (!visited[x] and equal(my, H[x])) {
						visited[x] = true;
						add.pb(x);
					}
				}
				res.pb(add);
			}
		}
	}
	if (n != 2) {
		for (auto r : res) {
			cout << size(r) << " ";
			for (auto x : r) {
				cout << x << " "; 
			} cout << endl;
		}
	} else {
		cout << 1 << " " << unions[0][0] << endl;
		cout << size(unions[0]) - 1 << " ";
		for (int i = 1; i < size(unions[0]); i++) {
			cout << unions[0][i] << " ";
		} cout << endl;
	}
	return 0;
}
