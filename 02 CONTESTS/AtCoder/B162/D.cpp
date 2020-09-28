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

struct RGB {
	int r, g, b;
};

int32_t main() { fastio;
	int n; cin >> n;
	string s; cin >> s;

	vector<RGB> pref(n + 1, { 0, 0, 0 }), suff(n + 1, { 0, 0, 0 });

	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i];
		if (s[i] == 'R') {
			pref[i + 1].r++;
		} else if (s[i] == 'G') {
			pref[i + 1].g++;
		} else {
			pref[i + 1].b++;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		suff[i] = suff[i + 1];
		if (s[i] == 'R') {
			suff[i].r++;
		} else if (s[i] == 'G') {
			suff[i].g++;
		} else {
			suff[i].b++;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int left = i - (j - i) - 1;
			int right = j + (j - i) + 1;
			if (s[i] != s[j]) {
				if (s[i] == 'R' and s[j] == 'G') {
					if (left >= 0 and left < n) {
						res += pref[left + 1].b;
					}
					if (right < n and right >= 0) {
						res += suff[right].b;
					}
				} else if (s[i] == 'R' and s[j] == 'B') {
					if (left >= 0 and left < n) {
						res += pref[left + 1].g;
					}
					if (right < n and right >= 0) {
						res += suff[right].g;
					}
				} else if (s[i] == 'G' and s[j] == 'B') {
					if (left >= 0 and left < n) {
						res += pref[left + 1].r;
					}
					if (right < n and right >= 0) {
						res += suff[right].r;
					}
				} else if (s[i] == 'G' and s[j] == 'R') {
					if (left >= 0 and left < n) {
						res += pref[left + 1].b;
					}
					if (right < n and right >= 0) {
						res += suff[right].b;
					}
				} else if (s[i] == 'B' and s[j] == 'G') {
					if (left >= 0 and left < n) {
						res += pref[left + 1].r;
					}
					if (right < n and right >= 0) {
						res += suff[right].r;
					}
				} else if (s[i] == 'B' and s[j] == 'R') {
					if (left >= 0 and left < n) {
						res += pref[left + 1].g;
					}
					if (right < n and right >= 0) {
						res += suff[right].g;
					}
				}
			}
		}
	}	    
	cout << res << endl;
    return 0;
}
