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
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

const int maxN = (int) 2e5 + 5;
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

signed main() { fastio;
	precomp();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		vector<int> freq(n + 5);
		for (auto &a : arr) {
			cin >> a;
			freq[a]++;
		}
		sort(_all(arr), greater<int>());
		int count = 0;
		for (int i = k; i < n; i++) {
			if (arr[i] == arr[k - 1]) count++;
		}
		cout << nck(freq[arr[k - 1]], count) << endl;
	}
	return 0;
}