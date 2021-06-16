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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

map<int, int> primeFactors(int n) {
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
   	map<int, int> mp;
   	for (auto f : factorization) {
   		mp[f.fs] = f.sc;
   	}
    return mp;
}

signed main() { fastio;
	int n, q; cin >> n >> q;
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	vector<map<int, int>> fcts;
	for (auto &a : arr) {
		fcts.pb(primeFactors(a));
	}
	vector<array<int, 2>> queries;
	while (q--) {
		int loc, val;
		cin >> loc >> val; loc--;
		queries.pb({ loc, val });
		auto xx = primeFactors(val);
		for (auto x : xx) {
			fcts[loc][x.fs] += x.sc;
		}
	}
	auto gcd_map = fcts[0];
	for (auto f : fcts) {
		map<int, int> gcd_map_new;
		for (auto x : f) {
			if (gcd_map.find(x.fs) != gcd_map.end()) {
				gcd_map_new[x.fs] = min(x.sc, gcd_map[x.fs]);
			}
		}
		gcd_map = gcd_map_new;
	}
	int gcd = 1;
	for (auto g : gcd_map) {
		gcd = _mul(fastpow(g.fs, g.sc), gcd);
	}
	reverse(_all(queries));
	vector<int> ans;
	for (auto q : queries) {
		ans.pb(gcd);
		auto xx = primeFactors(q[1]);
		for (auto x : xx) {
			fcts[q[0]][x.fs] -= x.sc;
			if (gcd_map.find(x.fs) != gcd_map.end()) {
				gcd = _mul(inv(fastpow(x.fs, gcd_map[x.fs])), gcd);
				gcd_map[x.fs] = min(gcd_map[x.fs], fcts[q[0]][x.fs]);
				gcd = _mul(fastpow(x.fs, gcd_map[x.fs]), gcd);
			}
		}
	}	
	reverse(_all(ans));
	for (auto a : ans) {
		cout << a << endl;
	}
	return 0;
}