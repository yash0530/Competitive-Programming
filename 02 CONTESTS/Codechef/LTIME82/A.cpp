#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL 1e18
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

const int maxP = 1e4 + 5, P = 1230;
vector<int> primes(maxP, true);

void add(vector<int> &lcm, int n) {
	for (int d = 2; d * d <= n; d++) {
		int count = 0;
        while (n % d == 0) {
            count++;
            n /= d;
        }
        lcm[d] = max(lcm[d], count);
    }
    if (n > 1) {
    	lcm[n] = max(lcm[n], 1LL);
    }
}

int inc(vector<int> &lcm, int n) {
	int num = 1;
	for (int d = 2; d * d <= n; d++) {
		int count = 0;
        while (n % d == 0) {
            count++;
            n /= d;
        }
        int inc = count - lcm[d];
        if (inc > 0) {
        	num *= fastpow(d, inc, HELL);
        }
    }
    if (n > 1) {
    	if (lcm[n] == 0) {
    		num *= n;
    	}
    }
    return num;
}

void solve() {
	int n, m, x;
	cin >> n >> m;
	vector<int> lcm(maxP, 0);
	for (int i = 0; i < n; i++) {
		cin >> x;
		add(lcm, x);
	}
	int curr = 1, val = 1;
	for (int i = 1; i <= m; i++) {
		x = inc(lcm, i);
		if (x > curr) {
			curr = x;
			val = i;
		}
	}
	cout << val << endl;
}

int32_t main() { fastio;

	for (int i = 2; i * i < maxP; i++) {
		if (primes[i]) {
			for (int j = i * i; j < maxP; j += i) {
				primes[j] = false;
			}
		}
	}

    int t; cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}