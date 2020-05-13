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
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int zc = 0;
	if (a == 0) zc++;
	if (b == 0) zc++;
	if (c == 0) zc++;
	map<char, int> m;
	m['A'] = a;
	m['B'] = b;
	m['C'] = c;
	vector<char> res;
	vector<string> arr(n);
	bool np = false;
	map<char, int> cc;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cc['A'] += arr[i][0] == 'A';
		cc['A'] += arr[i][1] == 'A';
		cc['B'] += arr[i][0] == 'B';
		cc['B'] += arr[i][1] == 'B';
		cc['C'] += arr[i][0] == 'C';
		cc['C'] += arr[i][1] == 'C';
	}
	for (auto s : arr) {
		if (m[s[0]] > m[s[1]]) {
			m[s[0]]--; m[s[1]]++;
			res.pb(s[1]);
			if (m[s[0]] < 0) np = true;
		} else {
			res.pb(s[0]);
			m[s[0]]++; m[s[1]]--;
			if (m[s[1]] < 0) np = true;
		}
	}
	if (np) {
		bool np = false;
		m['A'] = a;
		m['B'] = b;
		m['C'] = c;
		vector<char> res;
		for (auto s : arr) {
			if ((m[s[0]] - cc[s[0]] > m[s[1]] - cc[s[1]]) or m[s[1]] == 0) {
				m[s[0]]--; m[s[1]]++;
				res.pb(s[1]);
				if (m[s[0]] < 0) np = true;
			} else {
				res.pb(s[0]);
				m[s[0]]++; m[s[1]]--;
				if (m[s[1]] < 0) np = true;
			}
			cc[s[0]]--;
			cc[s[1]]--;
		}
		if (np) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
			for (auto r : res) cout << r << endl;
		}
	} else {
		cout << "Yes" << endl;
		for (auto r : res) cout << r << endl;
	}
	return 0;
}
