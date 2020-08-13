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

int32_t main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		set<int> zeros, ones;
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') zeros.insert(i);
			else ones.insert(i);
		}
		int curr = 1;
		while (!zeros.empty() or !ones.empty()) {
			if (zeros.empty()) {
				res[*ones.begin()] = curr;
				ones.erase(ones.begin());
			}
			else if (ones.empty()) {
				res[*zeros.begin()] = curr;
				zeros.erase(zeros.begin());
			}
			else if (*ones.begin() < *zeros.begin()) {
				bool now = false;
				res[*ones.begin()] = curr;
				int last = *ones.begin();
				ones.erase(ones.begin());
				while (true) {
					if (now) {
						auto x = ones.upper_bound(last);
						if (x == ones.end()) {
							break;
						}
						res[*x] = curr;
						last = *x;
						ones.erase(x);
					} else {
						auto x = zeros.upper_bound(last);
						if (x == zeros.end()) {
							break;
						}
						res[*x] = curr;
						last = *x;
						zeros.erase(x);
					}
					now = !now;
				}
			}
			else {
				bool now = true;
				res[*zeros.begin()] = curr;
				int last = *zeros.begin();
				zeros.erase(zeros.begin());
				while (true) {
					if (now) {
						auto x = ones.upper_bound(last);
						if (x == ones.end()) {
							break;
						}
						res[*x] = curr;
						last = *x;
						ones.erase(x);
					} else {
						auto x = zeros.upper_bound(last);
						if (x == zeros.end()) {
							break;
						}
						res[*x] = curr;
						last = *x;
						zeros.erase(x);
					}
					now = !now;
				}
			}
			curr++;
		}
		cout << *max_element(res.begin(), res.end()) << endl;
		for (auto r : res) {
			cout << r << " ";
		} cout << endl;
	}
	return 0;
}