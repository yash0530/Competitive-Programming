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

vector<int> mains(15);
const int maxN = 1e5 + 5;

bool check() {
	if (mains[8]) return true;
	if (mains[6] and mains[2] > 1) return true;
	if (mains[4] > 1) return true;
	if (mains[4] and mains[2] > 2) return true;
	return false;
}

int32_t main() {
	int n; cin >> n;
	vector<int> freq(maxN);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		freq[x]++;
	}
	for (int i = 0; i < maxN; i++) {
		for (int c = 1; c <= min((int) 8, freq[i]); c++) {
			mains[c]++;
		}
	}

	int q; cin >> q;
	while (q--) {
		char type;
		cin >> type >> x;
		if (type == '-') {
			freq[x]--;
			if (freq[x] < 8) {
				mains[freq[x] + 1]--;
			}
		} else {
			freq[x]++;
			if (freq[x] <= 8) {
				mains[freq[x]]++;
			}
		}
		if (check()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}