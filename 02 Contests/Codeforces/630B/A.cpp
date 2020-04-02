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
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;

	if ((a or b) and (x2 == x1)) {
		cout << "No" << endl;
		return;
	}
	
	if ((c or d) and (y2 == y1)) {
		cout << "No" << endl;
		return;
	}

	if ((x - x1) >= (a - b)) {
		if ((x2 - x) >= (b - a)) {
			if ((y - y1) >= (c - d)) {
				if ((y2 - y) >= (d - c)) {
					cout << "Yes" << endl;
					return;
				}
			}
		}
	}
	cout << "No" << endl;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}