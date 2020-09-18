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

const int maxN = 25;

void del(int prime) {
	cout << "B " << prime << endl;
	int x; cin >> x;
}

int getCount(int prime) {
	cout << "A " << prime << endl;
	int x; cin >> x;
	return x;
}

int32_t main() { fastio;
	vector<int> primes, seive(maxN, 1);
	for (int i = 2; i < maxN; i++) {
		if (seive[i]) {
			for (int j = i * i; j < maxN; j += i) {
				seive[j] = false;
			}
		}
	}
	for (int i = 2; i < maxN; i++) {
		if (seive[i]) {
			primes.pb(i);
		}
	}
	vector<int> vals;
	int count = maxN - 1, ans = 1;
	vector<int> removeit(maxN, 1);
	for (int i = 0; i < size(primes); i++) {
		if (i % 3 == 0) {
			int now = getCount(1);
			if (now > count) {
				deb(count);
				deb(now);
				for (int j = i - 3; j < i; j++) {
					if (getCount(primes[j])) {
						vals.pb(primes[j]);
					}
				}
				for (auto p : vals) {
					int curr = p;
					while (getCount(curr)) {
						ans *= p;
						curr *= p;
					}
				}
				for ( ; i < size(primes); i++) {
					int ct = 0;
					for (int a = primes[i]; a < maxN; a += primes[i]) {
						if (removeit[a]) {
							ct++;
						}
					}
					deb(primes[i]);
					deb(ct);
					if (getCount(primes[i]) != ct) {
						vals.pb(primes[i]);
						ans *= primes[i];
						break;
					}
				}
				break;		
			}
		}
		del(primes[i]);
		removeit[primes[i]] = false;
		count--;
		for (int j = primes[i] * primes[i]; j < maxN; j += primes[i]) {
			if (removeit[j]) {
				removeit[j] = false;
				count--;
			}
		}
		if (i == (size(primes) - 1)) {
			int now = getCount(1);
			if (now > count) {
				for (int j = 9500; j < maxN; j++) {
					if (getCount(primes[j])) {
						vals.pb(primes[j]);
						ans = primes[j];
					}
				}
			}
		}
	}
	cout << "C " << ans << endl;
	return 0;
}