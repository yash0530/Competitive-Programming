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

vector<int> getFactors(int n) {
    vector<int> factors = { 1 };
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    factors.pb(n);
    return factors;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> freq(128);
		for (auto x : s) {
			freq[x]++;
		}
		int ans = 1;
		bool done = false;
		for (int nn = n; nn >= 1; nn--) {
			for (int chr = 'a'; chr <= 'z'; chr++) {
				if (freq[chr] >= nn) {
					ans = nn;
					break;
				}
			}
			int kk = k % nn;
			if (kk) {
				kk = __gcd(kk, nn - kk);
			}
			if (kk == 0) {
				ans = nn;
				break;
			} else {
				auto fcts = getFactors(kk);
				for (auto x : fcts) {
					if ((nn % x) == 0) {
						int tt = nn / x;
						int count = 0;
						for (int chr = 'a'; chr <= 'z'; chr++) {
							count += (freq[chr] / tt);
						}
						if (count >= x) {
							ans = nn;
							done = true;
							break;
						}
					}
				}
				if (done) break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}