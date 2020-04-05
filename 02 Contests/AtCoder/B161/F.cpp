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

vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    factors.push_back(n);
    return factors;
}

int32_t main() { fastio;
    int n; cin >> n;

    if (n == 2) {
    	cout << 1 << endl;
    	return 0;
	}

	if (n == 3) {
		cout << 2 << endl;
		return 0;
	}

	int res = getFactors(n - 1).size();
	vector<int> factors = getFactors(n);
	for (auto i : factors) {
		int x = n;
    	while (x >= i) {
    		if (x % i == 0) {
    			x /= i;
    		} else {
    			x = x % i;
    		}
    	}
    	if (x == 1) {
    		res++;
    	}
	}
    cout << res << endl;
    return 0;
}
