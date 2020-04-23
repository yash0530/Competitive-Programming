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

int n, k;
string s;
const int maxN = 105;

int32_t main() { fastio;
	cin >> n >> k;
	cin >> s;
	queue<pair<string, int>> Q;
	Q.push({ s, 0LL });
	set<string> visited;
	visited.insert(s);
	int count = 0, res = 0;
	while (!Q.empty() and count < k) {
		string t = Q.front().first;
		int add = Q.front().second;
		Q.pop();
		count++;
		res += add;
		int x = size(t);
		for (int i = 0; i < x; i++) {
			string nx = t.substr(0, i) + t.substr(i + 1, x - i - 1);
			if (visited.find(nx) == visited.end()) {
				visited.insert(nx);
				Q.push({ nx, add + 1 });
			}
		}
	}
	if (count < k) {
		cout << -1 << endl;
	} else {
		cout << res << endl;
	}
    return 0;
}
