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

int nck(int n, int r) {
	if (!r) return 1;
	int num = 1, den = 1;
	while (true) {
		den = mul(den, r--);
		num = mul(num, n--);
		if (!r) break;
	}
	return mul(num, inv(den));
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> arr(n);
		vector<int> freq(n + 5);
		for (int i = 0; i < n - 1; i++) {
			cin >> arr[i];
			freq[arr[i]]++;
		}
		bool poss = true;
		for (int i = 2; i <= n; i++) {
			if (freq[i] and !freq[i - 1]) {
				poss = false;
			}
		}
		int res = 1;
		if (poss) {
			for (int i = 2; i <= n; i++) {
				if (freq[i])
					res = mul(res, fastpow(freq[i - 1], freq[i]));
			}
			int pairs = 0;
			for (auto f : freq) {
				pairs += ((f * (f - 1)) / 2);
			}
			if (m < (n - 1)) {
				cout << 0 << endl;
			} else {
				int avail = m - (n - 1);
				if (avail > pairs) {
					cout << 0 << endl;
				} else {
					res = mul(res, nck(pairs, avail));
					cout << res << endl;
				}
			}
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}