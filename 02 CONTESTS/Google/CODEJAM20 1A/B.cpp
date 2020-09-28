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

int n;
const int maxN = 1e3 + 5;
int pascal[maxN][maxN];
bool visited[maxN][maxN];
int count = 0;

bool solve(vector<pair<int, int>> &a, int sum) {
	if (sum == n) {
		return true;
	}
	if (size(a) > 500) {
		return false;
	}
	if (sum > n) {
		return false;
	}
	int l = a.back().first, r = a.back().second;

	if (l > r and !visited[l][r + 1]) {
		visited[l][r + 1] = true;
		a.push_back({ l, r + 1 });
		bool res = solve(a, sum + pascal[l][r + 1]);
		if (res) return true;
		a.pop_back();
	}
	if (!visited[l + 1][r]) {
		visited[l + 1][r] = true;
		a.push_back({ l + 1, r });
		bool res = solve(a, sum + pascal[l + 1][r]);
		if (res) return true;
		a.pop_back();
	}
	if (l > 0 and l > r and !visited[l - 1][r]) {
		visited[l - 1][r] = true;
		a.push_back({ l - 1, r });
		bool res = solve(a, sum + pascal[l - 1][r]);
		if (res) return true;
		a.pop_back();
	}
	if (l > 0 and r > 0 and !visited[l - 1][r - 1]) {
		visited[l - 1][r - 1] = true;
		a.push_back({ l - 1, r - 1 });
		bool res = solve(a, sum + pascal[l - 1][r - 1]);
		if (res) return true;
		a.pop_back();
	}
	if (r > 0 and !visited[l][r - 1]) {
		visited[l][r - 1] = true;
		a.push_back({ l, r - 1 });
		bool res = solve(a, sum + pascal[l][r - 1]);
		if (res) return true;
		a.pop_back();
	}
	if (!visited[l + 1][r + 1]) {
		visited[l + 1][r + 1] = true;
		a.push_back({ l + 1, r + 1 });
		bool res = solve(a, sum + pascal[l + 1][r + 1]);
		if (res) return true;
		a.pop_back();
	}
	return false;
}

int32_t main() { fastio;

	for (int line = 0; line < 60; line++) { 
        for (int i = 0; i <= line; i++) { 
        if (line == i or i == 0) 
            pascal[line][i] = 1; 
        else
            pascal[line][i] = pascal[line - 1][i - 1] + pascal[line - 1][i]; 
    	}
    }

	int t; cin >> t;
    for (int _ = 1; _ <= t; _++) {
    	memset(visited, 0, sizeof visited);
    	cout << "Case #" << _ << ":\n";
    	cin >> n;
    	vector<pair<int, int>> res = { { 0, 0 } };
    	visited[0][0] = true;
    	solve(res, 1);
    	for (auto r : res) {
    		cout << r.first + 1 << " " << r.second + 1 << endl;
    	}
	}
    return 0;
}
