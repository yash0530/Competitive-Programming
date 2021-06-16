#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

bool isPoss(string s, int x) {
	vector<int> ints;
	int part = x;
	int used = 0;
	for (int i = 0; (i + part) <= size(s); ) {
		string s1 = s.substr(i, part);
		bool yes = true;
		for (auto x : s1) {
			if (x != '9') yes = false;
		}
		used = i - 1 + part;
		i += part;
		part += yes;
		ints.pb(stoi(s1));
	}
	if (size(ints) >= 2) {
		for (int i = 1; i < size(ints); i++) {
			if ((ints[i] - ints[i - 1]) == 1);
			else return false;
		}
		if (used == (size(s) - 1))
			return true;
	} 
	return false;
}

bool poss(int n) {
	string s = to_string(n);
	int N = size(s);
	for (int i = 1; i * 2 <= N; i++) {
		if (isPoss(s, i)) {
			return true;
		}
	}
	return false;
}

void solve() {
	int n; cin >> n;
	n++;
	while (!poss(n)) {
		n++;
	}
	cout << n << endl;
}

signed main() { fastio;

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}