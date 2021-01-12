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
#define _all(aa) aa.begin(), aa.end()

vector<pii> primeFactors(int n) {
    vector<pii> factorization;
    int ct = 0;
    while (n % 2 == 0) {
        n /= 2;
        ct++;
    }
    if (ct) {
    	factorization.pb({ 2, ct });
    }
    for (int d = 3; d * d <= n; d += 2) {
        ct = 0;
        while (n % d == 0) {
        	ct++;
            n /= d;
        }
        if (ct) {
        	factorization.pb({ d, ct });
        }
    }
    if (n > 1)
        factorization.push_back({ n, 1 });
    return factorization;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		map<int, int> mp;
		for (auto &a : arr) {
			cin >> a;
			auto xx = primeFactors(a);
			int reqd = 1;
			for (auto x : xx) {
				if (x.sc & 1) {
					reqd *= x.fs;
				}
			}
			mp[reqd]++;
		}
		int ans_0 = 0, ans_1 = 0, tt = 0;
		for (auto x : mp) {
			ans_0 = max(ans_0, x.sc);
			if ((x.sc % 2 == 0) or (x.fs == 1)) {
				tt += x.sc;
			} else {
				ans_1 = max(ans_1, x.sc);
			}
		}
		ans_1 = max(ans_1, tt);
		int q, aa; cin >> q;
		while (q--) {
			cin >> aa;
			if (aa == 0) {
				cout << ans_0 << endl;
			} else {
				cout << ans_1 << endl;
			}
		}
	}
	return 0;
}