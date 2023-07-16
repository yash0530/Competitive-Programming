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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() { fastio;
	int n; cin >> n;
	if (n == 1) {
		cout << "1\n1\n";
		exit(0);
	}
	vector<int> primes(n + 1);
	vector<int> prime_hash(n + 1, 0);
	iota(primes.begin(), primes.end(), 0);
	for (int i = 2; i <= n; i++) {
		if (primes[i] == i) {
			for (int j = i; j <= n; j += i) {
				primes[j] = min(primes[j], i);
			}
			prime_hash[i] = rng();
		}
	}

	vector<int> fact_hash(n + 1, 0);
	map<int, int> rev_fact_hash;
	for (int i = 2; i <= n; i++) {
		fact_hash[i] = fact_hash[i - 1];
		int x = i;
		while (x != 1) {
			fact_hash[i] ^= prime_hash[primes[x]];
			x = x / primes[x];
		}
		rev_fact_hash[fact_hash[i]] = i;
	}

	int cum_hash = 0;
	for (int i = 1; i <= n; i++) {
		cum_hash ^= fact_hash[i];
	}
	vector<int> remove;
	if (cum_hash != 0) {
		if (rev_fact_hash.find(cum_hash) != rev_fact_hash.end()) {
			remove.pb(rev_fact_hash[cum_hash]);
		} else {
			for (int i = 2; i <= n; i++) {
				int new_hash = cum_hash ^ fact_hash[i];
				if (rev_fact_hash.find(new_hash) != rev_fact_hash.end()) {
					remove = { i, rev_fact_hash[new_hash] };
					break;
				}
			}
		}
		if (size(remove) == 0) {
			n--;
			remove = { 2, n / 2 };
		}
	}

	cout << n - size(remove) << endl;
	for (int i = 1; i <= n; i++) {
		if (find(remove.begin(), remove.end(), i) == remove.end()) cout << i << " ";
	}
	cout << endl;
	return 0;
}