// CSES Sum of Two Values
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
	int n, k, x;
	cin >> n >> k;
	map<int, vector<int>> MP;
	for (int i = 0; i < n; i++) {
		cin >> x;
		MP[x].pb(i);
	}
	int a = -1, b = -1;
	for (auto m : MP) {
		if (size(m.sc)) {
			if ((m.fs + m.fs) == k) {
				if (size(m.sc) > 1) {
					a = m.sc[0] + 1;
					b = m.sc[1] + 1;
					break;
				}
			} else {
				if (size(MP[k - m.fs])) {
					a = m.sc[0] + 1;
					b = MP[k - m.fs][0] + 1;
					break;
				}
			}
		}
	}
	if (a == -1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << a << " " << b << endl;
	}
	return 0;
}