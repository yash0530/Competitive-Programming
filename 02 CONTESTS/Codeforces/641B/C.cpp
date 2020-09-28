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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

const int maxN = (int) 2e5 + 5;
vector<int> freq[maxN];

vector<pii> primeFactors(int n) {
    vector<pii> factorization;
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    if (count) factorization.pb({ 2, count });
    for (int d = 3; d * d <= n; d += 2) {
    	count = 0;
        while (n % d == 0) {
            n /= d;
            count++;
        }
        if (count) factorization.push_back({ d, count });

    }
    if (n > 1)
        factorization.push_back({ n, 1 });
    return factorization;
}

int32_t main() { fastio;
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		auto pf = primeFactors(arr[i]);
		for (auto p : pf) {
			freq[p.fs].pb(p.sc);
		}
	}
	int ans = 1;
	for (int i = 0; i < maxN; i++) {
		if (size(freq[i]) == n - 1) {
			int curr = *min_element(freq[i].begin(), freq[i].end());
			ans = ans * fastpow(i, curr, INF);
		} else if (size(freq[i]) == n) {
			sort(freq[i].begin(), freq[i].end());
			ans = ans * fastpow(i, freq[i][1], INF);
		} 
	}
	cout << ans << endl;
	return 0;
}
