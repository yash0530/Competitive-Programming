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

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> freq(128);
		for (auto x : s) {
			freq[x]++;
		}
		if (n % k) {
			cout << -1 << endl;
		} else {
			bool poss = true;
			for (int chr = 'a'; chr <= 'z'; chr++) {
				if (freq[chr] % k) {
					poss = false;
					break;
				}
			}
			if (poss) {
				cout << s << endl;
			} else {
				int have = 0;
				for (int i = n - 1; i >= 0; i--) {
					freq[s[i]]--;
					for (char curr = s[i] + 1; curr <= 'z'; curr++) {
						freq[curr]++;
						int reqd = 0;
						for (int elem = 'a'; elem <= 'z'; elem++) {
							if (freq[elem] % k) {
								reqd += k - (freq[elem] % k);
							}
						}
						if (have >= reqd and (have - reqd) % k == 0) {
							for (int x = 0; x < i; x++) {
								cout << s[x];
							}
							cout << curr;
							int free = have - reqd;
							for (int i = 0; i < free; i++) {
								cout << 'a';
							}
							for (char elem = 'a'; elem <= 'z'; elem++) {
								if (freq[elem] and (freq[elem] % k)) {
									for (int i = 0; i < (k - (freq[elem] % k)); i++) {
										cout << elem;
									}	
								}
							}
							cout << endl;
							goto done;
						}
						freq[curr]--;
					}
					have++;
				}
			}
		}
		done:;
	}
	return 0;
}