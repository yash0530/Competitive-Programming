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

vector<char> curr, alpha = { '0', '1', 'a', 'A' };
vector<vector<char>> strs;
const int sz = 3;
vector<int> dist = { 0, 0, 0, 0 };

void getCombinations() {
	if (size(curr) == sz) {
		strs.push_back(curr);
		return;
	}
	for (auto a : alpha) {
		curr.push_back(a);
		getCombinations();
		curr.pop_back();
	}
}

int getVal(vector<int> a) {
	return (a[0] & a[1]) | a[2];
}

int evaluate(vector<int> a, vector<int> b) {
	int g0 = getVal(a);
	int g1 = getVal(b);

	if (g0 == g1) {
		if (g0 == 0) {
			return 3;
		} else {
			return 0;
		}
	} else {
		if (g0 == 0) {
			return 1;
		} else {
			return 2;
		}
	}
}

void solve() {
	for (auto &s : strs) {
		vector<int> g0, g1;
		for (auto x : s) {
			if (x == '0') {
				g0.push_back(0);
				g1.push_back(0);
			} else if (x == '1') {
				g0.push_back(1);
				g1.push_back(1);
			} else if (x == 'a') {
				g0.push_back(0);
				g1.push_back(1);
			} else {
				g0.push_back(1);
				g1.push_back(0);
			}
		}
		int res = evaluate(g0, g1);	
		s.push_back(res + '0');
		dist[res]++;
	}
}

int32_t main() { fastio;
	getCombinations();
	solve();
	deba(dist);
    return 0;
}
