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

void solve() {
	string s, h; cin >> s;
	cin >> h;
	vector<int> freqS(128), freqH(128);
	for (auto x : s) {
		freqS[x]++;
	}
	int len = s.length(), hen = h.length();
	if (hen < len) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i < hen; i++) {
		if (i >= len) {
			freqH[h[i - len]]--;
		}
		freqH[h[i]]++;
		bool found = true;
		for (int i = 0; i < 128; i++) {
			if (freqS[i] != freqH[i]) {
				found = false;
				break;
			}
		}
		if (found) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

int32_t main() { fastio;
    
    int t; cin >> t;
    while (t--) {
    	solve();
    }

    return 0;
}
