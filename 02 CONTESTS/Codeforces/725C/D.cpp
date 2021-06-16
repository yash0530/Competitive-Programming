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
#define Mat vector<vector<int>>
#define getMat(aa, bb) vector<vector<int>>(aa, vector<int>(bb, 0))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

vector<pii> primeFactors(int n) {
    vector<pii> factorization;
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    if (count) factorization.pb({ 2, count });
    for (int d = 3; d * d <= n; d += 2) {
    	count = 0;
        while (n % d == 0) {
            n /= d;
            count++;
        }
        if (count) factorization.push_back({ d, count });

    }
    if (n > 1)
        factorization.push_back({ n, 1 });
    return factorization;
}


signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int gg = __gcd(n, m);

		vector<pii> nff = primeFactors(n / gg);
		vector<pii> mff = primeFactors(m / gg);
		vector<pii> gff = primeFactors(gg);

		int count = (size(nff) > 0) + (size(mff) > 0);

		if (k < count) {
			cout << "NO" << endl;
		}
		else if (k == count) {
			cout << "YES" << endl;
		}
		else {
			int v1 = 0, v2 = 0, v3 = 0;
			for (auto x : nff) {
				v1 += x.sc;
			}
			for (auto x : mff) {
				v2 += x.sc;
			}
			for (auto x : gff) {
				v3 += x.sc;
			}

			count = v1 + v2 + 2 * v3;
			if (k <= (v1 + v2)) {
				cout << "YES" << endl;
			}
			else if (k > count) {
				cout << "NO" << endl;
			}
			else {
				if (((count == 2) and (n == m)) and k == 1) {
					cout << "NO" << endl;
				} else {
					cout << "YES" << endl;
				}
			}
		}
	}
	return 0;
}
