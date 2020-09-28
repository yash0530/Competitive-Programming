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

int minimize(vector<int> chunks, int k) {
	priority_queue<int> pq;
	for (auto c : chunks) {
		pq.push(c);
	}
	while (!pq.empty() and k >= 2) {
		k -= 2;
		pq.pop();
	}
	int rem = 0;
	while (!pq.empty()) {
		rem += pq.top(); pq.pop();
	}
	return rem;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		vector<int> chunks;
		char prev = '2';
		for (auto x : s) {
			if (prev != x) chunks.pb(1);
			else chunks[size(chunks) - 1]++;
			prev = x;
		}
		vector<int> zeros;
		int ans = INF;
		if (s[0] == '0') {
			for (int i = 0; i < size(chunks); i += 2) {
				zeros.pb(chunks[i]);
			}
		} else {
			for (int i = 1; i < size(chunks); i += 2) {
				zeros.pb(chunks[i]);
			}
		}
		if ((s[0] == s.back()) and (size(zeros) == 1) and (s[0] == '0')) {
			cout << 0 << endl;
		} else if (size(zeros) == 1) {
			if (k >= 2) cout << 0 << endl;
			else if (k == 1) {
				if (s[0] == '0' or s.back() == '0') {
					cout << 0 << endl;
				} else {
					cout << zeros[0] << endl;
				}
			} else {
				cout << zeros[0] << endl;
			}
		} else if (size(zeros) == 0) {
			cout << 0 << endl;
		} else {
			if (k >= 1) {
				if (s[0] == '0') {
					vector<int> temp(zeros.begin() + 1, zeros.end());
					ans = min(ans, minimize(temp, k - 1));
				}
				if (s.back() == '0') {
					vector<int> temp = zeros;
					temp.pop_back();
					ans = min(ans, minimize(temp, k - 1));
				}
			}
			if (k >= 2) {
				if ((s[0] == s.back()) and s[0] == '0') {
					vector<int> temp(zeros.begin() + 1, zeros.end());
					temp.pop_back();
					ans = min(ans, minimize(temp, k - 2));
				}
			}
			ans = min(ans, minimize(zeros, k));
			cout << ans << endl;	
		}
	}
	return 0;
}