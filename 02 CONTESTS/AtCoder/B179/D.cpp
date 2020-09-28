#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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

int n;
const int maxN = 2e5 + 5;
int tree[maxN];

void update(int index, int val) {
    while (index <= n) {
        tree[index] = (tree[index] + val) % HELL;
        index += (index & -index);
    }
}

int read(int index) {
    int sum = 0;
    while (index) {
        sum = (sum + tree[index]) % HELL;
        index -= (index & -index);
    }
    return sum;
}

int getSum(int low, int high) {
	if (high <= 0) {
		return 0;
	}
	if (low <= 1) {
		return read(high);
	}
	return (read(high) - read(low - 1) + HELL) % HELL;
}

int32_t main() { fastio;
	int k, a, b;
	cin >> n >> k;
	vector<vector<int>> s;
	while (k--) {
		cin >> a >> b;
		s.pb({ a, b });
	}
	update(1, 1);
	for (int i = 2; i <= n; i++) {
		for (auto x : s) {
			update(i, getSum(i - x[1], i - x[0]));
		}
	}
	cout << (read(n) - read(n - 1) + HELL) % HELL << endl;
	return 0;
}