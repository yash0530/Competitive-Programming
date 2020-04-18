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

// ay = bx + c
vector<double> getLine(pair<int, int> p1, pair<int, int>  p2) {
	double a = p1.first - p2.first;
	double b = p1.second - p2.second;
	double c = p1.second * (p1.first - p2.first) - p1.first * (p1.second - p2.second);
	int g = __gcd((int) abs(a), (int) abs(b));
	a /= g; b /= g; c /= g;
	if (a < 0 or (a == 0 and b < 0)) {
		a *= -1; b *= -1; c *= -1;
	}
	return { a, b, c };
}

int32_t main() { fastio;
	int n; cin >> n;
	vector<pair<int, int>> ps(n);
	for (int i = 0; i < n; i++) {
		cin >> ps[i].first >> ps[i].second;
	}	    
	set<vector<double>> lines;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			lines.insert(getLine(ps[i], ps[j]));
		}
	}
	int sz = size(lines);
	int count = 0;
	map<pair<double, double>, int> H;
	for (auto l : lines) {
		H[{ l[0], l[1] }]++;
	}
	for (auto h : H) {
		count += h.second * (sz - h.second);
	}
	cout << count / 2 << endl;

    return 0;
}