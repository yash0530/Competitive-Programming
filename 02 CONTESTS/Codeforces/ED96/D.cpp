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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		char prev = '2';
		vector<int> blocks, left;
		for (int i = 0; i < n; i++) {
			if (prev != s[i]) {
				blocks.pb(1);
			} else {
				blocks[size(blocks) - 1]++;
			}
			prev = s[i];
		}
		int m = size(blocks);
		for (int i = 0; i < m; i++) {
			if (blocks[i] > 1) {
				left.pb(i);
			}
		}
		reverse(left.begin(), left.end());
		int count = 0;
		for (int i = 0; i < m; i++) {
			if (i == (m - 1)) {
			} else {
				if (size(left) and (left.back() == i)) {
					left.pop_back();
				} else {
					if (size(left)) {
						blocks[left[size(left) - 1]]--;
						if (blocks[left.back()] == 1) {
							left.pop_back();
						}
					} else {
						i++;
					}
				}
			}
			count++;
		}
		cout << count << endl;
	}
	return 0;
}