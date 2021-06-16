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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

int val(vector<int> &arr, vector<int> &brr) {
	int n = size(arr);
	int m = size(brr);

	vector<int> su(n + 1);
	for (int i = n - 1; i >= 0; i--) {
		if (binary_search(_all(brr), arr[i])) {
			su[i]++;
		}
		su[i] += su[i + 1];
	}

	int ans = 0;
	int a = 0, b = 0;
	while (b < m) {
		while (a < n) {
			if (arr[a] > (brr[b] + a)) break;
			a++;
		}
		int curr = su[a];
		curr += (lower_bound(_all(brr), brr[b] + a) - brr.begin()) - b;
		ans = max(curr, ans);
		b++;
	}

	return ans;
}

signed main() { fastio;
	
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> arr(n), brr(m);
		vector<int> A1, A2, B1, B2;
		for (auto &a : arr) {
			cin >> a;
			if (a > 0) {
				A1.pb(a);
			} else {
				A2.pb(-a);
			}
		}
		for (auto &b : brr) {
			cin >> b;
			if (b > 0) {
				B1.pb(b);
			} else {
				B2.pb(-b);
			}
		}
		reverse(_all(A2));
		reverse(_all(B2));
		cout << val(A1, B1) + val(A2, B2) << endl;
	}

	return 0;
}