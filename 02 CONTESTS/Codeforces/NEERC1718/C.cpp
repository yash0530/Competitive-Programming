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

vector<int> getFactors(int n) {
    vector<int> factors = { 1 };
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    factors.pb(n);
    return factors;
}

signed main() { fastio;
	int n; cin >> n;
	string s; cin >> s;
	vector<int> FREQ(128);
	for (auto x : s) FREQ[x]++;
	auto fcts = getFactors(n);
	bool odd = false;
	for (auto f : FREQ) {
		if (f & 1) odd = true;
	}
	sort(_all(fcts));
	for (int i = size(fcts) - 1; i >= 0; i--) {
		int curr = fcts[i];
		vector<int> freq(_all(FREQ));
		if (curr % 2 == 0 and (!odd)) {
			cout << n / curr << endl;
			int now = 0;
			for (int i = 0; i < (n / curr); i++) {
				vector<char> res(curr);
				int loc = 0;
				while ((2 * loc) < curr and (now < 128)) {
					if (freq[now]) {
						res[loc] = now;
						res[curr - loc - 1] = now;
						freq[now] -= 2;
						loc++;
					} else {
						now++;
					}
				}
				for (auto r : res) cout << r;
				cout << " ";
			}
			break;
		} else if (curr & 1) {
			vector<int> freq(_all(FREQ));
			int now = 0;
			bool poss = false;
			set<char> odds;
			for (int i = 0; i < 128; i++) {
				if (freq[i] & 1) {
					odds.insert(i);
				}
			}
			for (int i = 0; i < (n / curr); i++) {
				int loc = 0;
				int toget = curr - 1;
				while ((2 * loc) < toget and (now < 128)) {
					if (freq[now] > 1) {
						freq[now] -= 2;
						loc++;
					} else {
						now++;
					}
				}
				if ((2 * loc) < toget) {
					poss = false;
					break;
				}
				if (size(odds)) {
					char curr = *odds.begin();
					odds.erase(curr);
					freq[curr]--;
				} else {
					while (now < 128) {
						if (freq[now]) {
							freq[now]--;
							odds.insert(now);
							break;
						}
						now++;
					}
				}
				poss = true;
			}
			if (poss) {
				cout << n / curr << endl;
				vector<int> freq(_all(FREQ));
				int now = 0;
				set<char> odds;
				for (int i = 0; i < 128; i++) {
					if (freq[i] & 1) {
						odds.insert(i);
					}
				}
				for (int i = 0; i < (n / curr); i++) {
					int loc = 0;
					int toget = curr - 1;
					vector<char> res(curr);
					while ((2 * loc) < toget and (now < 128)) {
						if (freq[now] > 1) {
							res[loc] = now;
							res[curr - loc - 1] = now;
							freq[now] -= 2;
							loc++;
						} else {
							now++;
						}
					}
					if (size(odds)) {
						char curr = *odds.begin();
						odds.erase(curr);
						res[loc] = curr;
						freq[curr]--;
					} else {
						while (now < 128) {
							if (freq[now]) {
								freq[now]--;
								res[loc] = now;
								odds.insert(now);
								break;
							}
							now++;
						}
					}
					for (auto x : res) {
						cout << x;
					} cout << " ";
				}
				break;
			}
		}
	}
	return 0;
}