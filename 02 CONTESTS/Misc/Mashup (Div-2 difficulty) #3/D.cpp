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
#define size(a) (int) a.size()

int32_t main() { fastio;
	string s; cin >> s;
	int n = size(s);

	int count = 0, open = 0, closed = 0;
	for (auto x : s) {
		count += (x == '#');
		open += (x == '(');
		closed += (x == ')');
	}

	int used = 0;
	string nw;
	int x = open - closed - count + 1;
	if (x < 1) {
			deb("YO");

		cout << -1 << endl;
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '#') {
			used++;
			if (used == count) {
				for (int j = 0; j < x; j++) {
					nw.push_back(')');
				}
			} else {
				nw.push_back(')');
			}
		} else {
			nw.push_back(s[i]);
		}
	}

	int stat = 0;
	for (auto a : nw) {
		stat += (a == '(');
		stat -= (a == ')');
		if (stat < 0) {
			cout << -1 << endl;
			exit(0);
		}
	}
	
	for (int i = 0; i < count - 1; i++) {
		cout << 1 << endl;
	}
	cout << x << endl;
    return 0;
}
