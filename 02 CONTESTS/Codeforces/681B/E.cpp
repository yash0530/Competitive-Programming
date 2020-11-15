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

int findFirstNumIndex(int& k, int n) {
	if (n == 1) return 0;
	n--;
	int first_num_index;
	int n_partial_fact = n;
	while (k >= n_partial_fact and n > 1) {
		n_partial_fact = n_partial_fact * (n - 1);
		n--;
	}
	first_num_index = k / n_partial_fact;
	k = k % n_partial_fact;
	return first_num_index;
}
vector<int> findKthPermutation(int n, int k) {
	vector<int> ans;
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	set<int>::iterator itr;
	itr = s.begin(); k--;
	for (int i = 0; i < n; i++) {
		int index = findFirstNumIndex(k, n - i);
		advance(itr, index);
		ans.pb(*itr);
		s.erase(itr);
		itr = s.begin();
	}
	return ans;
}

int firstPart(int l, int r) {
	int ans = r * (r + 1) / 2;
	ans -= l * (l - 1) / 2;
	return ans;
}

int lastPart(int n, int k, int l, int r, int mul) {
	vector<int> arr = findKthPermutation(n, k);
	return accumulate(arr.begin() + l - 1, arr.begin() + r, 0LL) + mul * (r - l + 1);
}

signed main() { fastio;
	int n, q;
	cin >> n >> q;
	int mul_fact = 0, loc = 1;
	if (n > 15) {
		mul_fact += n - 15;
	}
	int type, a, b;
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> a >> b;
			int ans = 0;
			if (a <= (n - 15)) {
				ans += firstPart(a, min(b, n - 15));
			}
			if (b > (n - 15)) {
				ans += lastPart(min(15LL, n),loc, max(a, n - 15 + 1) - max(0LL, n - 15), b - max(0LL, n - 15), mul_fact);
			}
			cout << ans << endl;
		} else {
			cin >> a; loc += a;
		}
	}
	return 0;
}