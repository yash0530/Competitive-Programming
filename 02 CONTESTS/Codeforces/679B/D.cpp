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
	int n, x; char ch; cin >> n;
	stack<int> st;
	vector<int> res(n);
	vector<pair<char, int>> okays;
	bool poss = true;
	for (int i = 1, j = 0; i <= (2 * n); i++) {
		cin >> ch;
		okays.pb({ ch, -1 });
		if (ch == '-') {
			cin >> x;
			okays[i - 1].sc = x;
			if (st.empty()) {
				poss = false;
				break;
			} else {
				res[st.top()] = x;
				st.pop();
			}
		} else {
			st.push(j++);
		}
	}
	if (poss) {
		int i = 0;
		set<int> ss;
		for (auto x : okays) {
			if (x.fs == '-') {
				if (*ss.begin() != x.sc) {
					poss = false;
				}
				ss.erase(ss.begin());
			} else {
				ss.insert(res[i++]);
			}
		}
	}
	if (poss) {
		cout << "YES" << endl;
		for (auto &r : res) {
			cout << r << " ";
		} cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}