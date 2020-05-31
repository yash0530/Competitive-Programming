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

int n, m;

// O(100)
bool check(string x, vector<string> &ss) {
	for (auto s : ss) {
		int count = 0;
		for (int i = 0; i < m; i++) {
			if (s[i] != x[i]) {
				count++;
			}
		}
		if (count > 1) return false;
	}
	return true;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<string> ss(n);
		for (int i = 0; i < n; i++) {
			cin >> ss[i];
		}
		string res = "-1";
		bool found = false;
		for (int j = 0; j < m; j++) {
			for (char i = 'a'; i <= 'z'; i++) {
				string temp = ss[0];
				temp[j] = i;
				if (check(temp, ss)) {
					found = true;
					res = temp;
					break;
				}
			}
			if (found) break;
		}
		cout << res << endl;
	}
	return 0;
}
