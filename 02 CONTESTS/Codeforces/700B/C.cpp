#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
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

int n;

int getNum(int i) {
	cout << "? " << i << endl;
	int x; cin >> x;
	return x;
}

void printRes(int low, int high) {
	vector<int> res;
	if (low == 1) {
		res.pb(INF);
	} else {
		res.pb(getNum(low - 1));
	}
	for (int i = low; i <= high; i++) {
		res.pb(getNum(i));
	}
	if (high == n) {
		res.pb(INF);
	} else {
		res.pb(getNum(high + 1));
	}
	for (int i = 1; i <= (high - low + 1); i++) {
		if (res[i] < min(res[i - 1], res[i + 1])) {
			cout << "! " << low + i - 1 << endl;
			return;
		}
	}
}

signed main() { fastio;
	cin >> n;
	int low = 1, high = n;
	while (low <= high) {
		if ((high - low) <= 20) {
			printRes(low, high);
			break;
		}
		int mid = (low + high) / 2;
		int v1 = getNum(mid - 1);
		int v2 = getNum(mid);
		if (v1 > v2) {
			low = mid;
		} else {
			high = mid;
		}
	}
	return 0;
}