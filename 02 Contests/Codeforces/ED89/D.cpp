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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n; cin >> n;
	int maxN = 1e7 + 5;
	vector<int> divs(maxN, -1);
	for (int i = 2; i < maxN; i++) {
		if (divs[i] == -1) {
			divs[i] = i;
			for (int j = i * i; j < maxN; j += i) {
				if (divs[j] == -1) {
					divs[j] = i;
				}
			}
		}
	}
	int x;
	vector<int> a(n, -1), b(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> x;
		int v = x;
		map<int, int> M;
		while(divs[v] != -1) {
			M[divs[v]]++;
			v = v / divs[v];
		}
		vector<pii> ds(M.begin(), M.end());
		if (size(ds) > 1) {
			a[i] = ds[0].fs;
			b[i] = 1;
			for (int j = 1; j < size(ds); j++) {
				b[i] *= ds[j].fs;
			}
		}
	}
	for (auto y : a) cout << y << " ";
	cout << endl;
	for (auto y : b) cout << y << " ";
	cout << endl;
	return 0;
}
