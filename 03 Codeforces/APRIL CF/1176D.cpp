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

int32_t main() { fastio;
	
	const int maxP = 3e6 + 5;
	vector<int> sieve(maxP, 1);
	for (int i = 2; i * i <= maxP; i++) {
		if (sieve[i] == 1) {
			for (int j = i * i; j < maxP; j += i) {
				if (sieve[j] == 1) {
					sieve[j] = j / i;
				}
			}
		}
	}
	map<int, int> primes;
	for (int i = 2, loc = 1; i < maxP; i++) {
		if (sieve[i] == 1) {
			primes[i] = loc++;
		}
	}

	int n, x; cin >> n;
	multiset<int> ms;
	for (int i = 0; i < 2 * n; i++) {
		cin >> x; ms.insert(x);
	}
	vector<int> arr;
	while (!ms.empty()) {
		int mx = *ms.rbegin();
		if (sieve[mx] == 1) {
			arr.push_back(primes[mx]);
			ms.erase(ms.find(mx));
			ms.erase(ms.find(primes[mx]));
		} else {
			arr.push_back(mx);
			ms.erase(ms.find(mx));
			ms.erase(ms.find(sieve[mx]));
		}
	}
	for (auto a : arr) {
		cout << a << " ";
	} cout << endl;

    return 0;
}
