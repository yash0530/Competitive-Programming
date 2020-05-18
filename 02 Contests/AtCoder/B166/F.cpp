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
	map<char, int> M;
	M['A'] = a; M['B'] = b; M['C'] = c;
	if (a + b + c == 0) {
		cout << "No" << endl;
	} else if (a + b + c == 1) {
		bool poss = true; string s;
		vector<char> res;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (M[s[0]] == 0 and M[s[1]] == 0) {
				poss = false;
				break;
			}
			if (M[s[0]]) {
				res.pb(s[1]);
				M[s[0]]--;
				M[s[1]]++;
			} else {
				res.pb(s[0]);
				M[s[0]]++;
				M[s[1]]--;
			}
		}
		if (poss) {
			cout << "Yes" << endl;
			for (auto r : res) cout << r << endl;
		} else {
			cout << "No" << endl;
		}
	} else {
		vector<string> inps(n);
		for (string &inp : inps) cin >> inp;
		vector<char> res;
		if (M[inps[0][0]] == 0 and M[inps[0][1]] == 0) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
			for (int i = 0; i < n - 1; i++) {
				if (M[inps[i][0]] and !M[inps[i][1]]) {
					
				} 
				if (inps[i][0] != inps[i + 1][0] and inps[i][0] != inps[i + 1][1]) {
					cout << inps[i][1] << endl;
					M[inps[i][0]]--;
					M[inps[i][1]]++;
				} else {
					cout << inps[i][0] << endl;
					M[inps[i][1]]--;
					M[inps[i][0]]++;
				}
			}
			if (M[inps[n - 1][0]]) {
				cout << inps[n - 1][1] << endl;
			} else {
				cout << inps[n - 1][0] << endl;
			}
		}
	}
	return 0;
}
