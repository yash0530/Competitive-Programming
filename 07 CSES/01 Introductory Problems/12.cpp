// CSES Palindrome Reorder
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

int32_t main() { fastio;
	string s; cin >> s;
	int n = size(s);
	vector<int> freq(128);
	for (auto x : s) freq[x]++;
	int count = 0;
	for (auto f : freq) {
		count += (f & 1);
	}
	if (((n % 2 == 0) and count >= 1) or ((n & 1) and count > 1)) {
		cout << "NO SOLUTION" << endl;
	} else {
		vector<char> res(n);
		int i = 0, j = n - 1, pos = 0;
		while (i <= j) {
			while ((pos < 128) and freq[pos] == 0) pos++;
			while ((pos < 128) and freq[pos]) {
				if (freq[pos] == 1) {
					res[n / 2] = pos;
					freq[pos]--;
				} else {
					res[i++] = pos;
					res[j--] = pos;
					freq[pos] -= 2;
				}
			}
			if (pos == 128) break;
		}
		for (auto r : res) cout << r;
		cout << endl;
	}
	return 0;
}