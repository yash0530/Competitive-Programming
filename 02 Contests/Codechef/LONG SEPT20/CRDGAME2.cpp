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

const int maxN = 200005;
vector<int> invN(maxN), fact(maxN), invFact(maxN);
void precomp() {
    fact[0] = fact[1] = invFact[0] = invFact[1] = invN[0] = invN[1] = 1;
    for (int i = 2; i < maxN; i++) {
        invN[i] = mul(HELL - (HELL / i), invN[HELL % i] % HELL);
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = mul(invN[i], invFact[i - 1]);
    }
}
int nck(int n, int k) {
    return mul(invFact[n - k], mul(fact[n], invFact[k]));
}

int32_t main() { fastio;
	precomp();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		int mx = *max_element(arr.begin(), arr.end());
		int count = 0;
		for (auto a : arr) {
			if (mx == a) count++;
		}
		int atleast = (count / 2) + 1;
		int ans = 0;
		for (int i = atleast; i <= count; i++) {
			ans = (mul(nck(count, i), fastpow(2, n - count)) + ans) % HELL;
		}
		cout << mul(2, ans) << endl;
	}
	return 0;
}