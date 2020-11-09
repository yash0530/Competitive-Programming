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

int n, x, pos;

const int maxN = (int) 2e3 + 5;
vector<int> fact(maxN);
void precomp() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
}

int getRes(int low, int high, int sm, int lg) {
	if (low >= high) {
		if (low and (low - 1) == pos) {
			return fact[sm + lg];
		}
		return 0;
	}
	int mid = (low + high) / 2;
	if (mid <= pos) {
		if (mid == pos) {
			return getRes(mid + 1, high, sm, lg);
		} else if (sm) {
			return mul(sm, getRes(mid + 1, high, sm - 1, lg));
		}
	} else {
		if (lg) {
			return mul(lg, getRes(low, mid, sm, lg - 1));
		}
	}
	return 0;
}

int32_t main() { fastio;
	precomp();
	cin >> n >> x >> pos;
	cout << getRes(0, n, x - 1, n - x) << endl;
	return 0;
}