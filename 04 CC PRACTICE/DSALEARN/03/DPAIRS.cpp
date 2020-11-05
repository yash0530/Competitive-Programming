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

int32_t main() { fastio;
	int n, m;
	cin >> n >> m;
	vector<pii> A(n), B(m);
	for (int i = 0; i < n; i++) {
		cin >> A[i].fs;
		A[i].sc = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i].fs;
		B[i].sc = i;
	}
	sort(_all(A));
	sort(_all(B));

	int i = 0, j = 0;
	cout << A[0].sc << " " << B[0].sc << endl;
	while (i < n and j < m) {
		if (i == (n - 1) or j == (m - 1)) break;
		cout << A[i].sc << " " << B[i + 1].sc << endl;
		cout << A[i + 1].sc << " " << B[i + 1].sc << endl;
		i++; j++;
	}
	while (i != (n - 1)) {
		i++;
		cout << A[i].sc << " " << B.back().sc << endl;
	}
	while (j != (m - 1)) {
		j++;
		cout << A.back().sc << " " << B[j].sc << endl;
	}
	return 0;
}