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

int getSum(int n) {
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int32_t main() { fastio;
    int n; cin >> n;

    int nr = sqrt(n);
    while (((nr * nr + nr * 163)) >= n) {
    	if (((nr * nr) + nr * getSum(nr)) == n) {
    		cout << nr << endl;
    		return 0;
    	}
    	nr--;
    }
    cout << -1 << endl;

    return 0;
}
