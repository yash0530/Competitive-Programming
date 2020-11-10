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
	vector<int> freq(1e5 + 5);
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (auto &a : arr) cin >> a;
		int low = 0, high = 0, size = 0;
		int count = 0, ans = 0;
		while (low < n) {
			if (high == n) {
				freq[arr[low]]--;
				low++;
			} else {
				freq[arr[high]]++;
				if (freq[arr[high]] == 1) {
					count++;
				}
				if (count < k) {
					ans = max(ans, high - low + 1);
				} else {
					while (count == k) {
						freq[arr[low]]--;
						if (freq[arr[low]] == 0) {
							count--;
						}
						low++;
					}
				}
				high++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}