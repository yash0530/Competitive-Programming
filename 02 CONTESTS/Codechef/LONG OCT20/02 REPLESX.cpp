#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, p, k, x;
		cin >> n >> x >> p >> k;
		vector<int> elements(n);
		for (auto &x : elements) {
			cin >> x;
		}
		bool not_found = false;
		sort(elements.begin(), elements.end());
		p--;k--;

		if (find(elements.begin(), elements.end(), x) == elements.end()) {
			not_found = true;
			elements[k] = x;
			sort(elements.begin(), elements.end());
		}

		vector<int> exes;
		for (int i = 0; i < n; i++) {
			if (elements[i] == x) {
				exes.pb(i);
			}
		}
		deb(p);
		deb(k);
		if (elements[p] == x) {
			cout << not_found << endl;
			continue;
		}
		if (p == k) {
			// x - k(p)
			if (exes.back() < k) {
				cout << p - exes.back() + not_found << endl;
			} 
			// k(p) - x
			else {
				cout << exes.front() - p + not_found << endl;
			}
			continue;
		}

		if (p > k) {
			// k - p - x
			if (exes.front() > p) {
				cout << exes.front() - p + not_found << endl;
				continue;
			}
		}

		if (p < k) {
			// x - p - k
			if (exes.back() < p) {
				cout << p - exes.back() + not_found << endl;
				continue;
			}
		}

		cout << -1 << endl;
	}
	return 0;
}