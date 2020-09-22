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

vector<pii> primeFactors(int n) {
    vector<pii> facts;
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
	if (count) facts.pb({ 2, count }); 
    for (int d = 3; d * d <= n; d += 2) {
        count = 0;
        while (n % d == 0) {
            n /= d;
            count++;
        }
        if (count) facts.pb({ d, count });
    }
    if (n > 1)
        facts.push_back({ n, 1 });
    return facts;
}

set<int> getFactors(int n) {
    set<int> factors;
    for (int i = 2; (i * i) <= n; i++) {
        if (n % i == 0) {
            factors.insert(i);
            if ((i * i) != n) {
                factors.insert(n / i);
            }
        }
    }
    factors.insert(n);
    return factors;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pii> primes = primeFactors(n);
		set<int> divisors = getFactors(n);
		if (size(divisors) <= 2) {
			for (auto d : divisors) cout << d << " ";
			cout << endl << 0 << endl;
			continue;
		}
		if(size(primes) == 2) {
			if ((primes[0].sc + primes[1].sc) == 2) {
				for (auto d : divisors) cout << d << " ";
				cout << endl << 1 << endl;
				continue;
			}
		}
		for (int i = 0; i < size(primes); i++) {
			divisors.erase(primes[i].fs);
			divisors.erase(primes[i].fs * primes[(i + 1) % size(primes)].fs);
		}
		vector<int> res;
		for (int i = 0; i < size(primes); i++) {
			res.pb(primes[i].fs);
			vector<int> added;
			for (auto x : divisors) {
				if ((x % primes[i].fs) == 0) {
					res.pb(x);
					added.pb(x);
				}
			}
			for (auto x : added) {
				divisors.erase(x);
			}
			if ((i == 0) and size(primes) == 2);
			else res.pb(primes[i].fs * primes[(i + 1) % size(primes)].fs);
		}
		for (auto x : res) cout << x << " ";
		cout << endl << 0 << endl;
	}
	return 0;
}