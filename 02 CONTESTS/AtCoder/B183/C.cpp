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

signed main() { fastio;

	int n, t;
	cin >> n >> t;
	getMat(adj, n + 1, n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> adj[i][j];
		}
	}
	vector<int> arr(n - 1);
	for (int i = 1; i <= n; i++) arr[i - 1] = i + 1;
	int count = 0;
	do {
		int val = adj[1][arr[0]] + adj[arr.back()][1];
		for (int i = 1; i < size(arr); i++) {
			val += adj[arr[i - 1]][arr[i]];
		}
		if (val == t) count++;
    } while (next_permutation(_all(arr))); 
    cout << count << endl;
	return 0;
}