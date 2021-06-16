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

map<pii, int> MP;

int getAns(int l, int r) {
	if (MP.find({ l, r }) != MP.end()) {
		return MP[{ l, r }];
	}
	int x; cout << "? " << l << " " << r << endl;
	cin >> x;
	MP[{ l, r }] = x;
	return x;
}

signed main() {
	int n; cin >> n;
	int low = 1, high = n;
	while ((high - low) > 1) {
		int p = getAns(low, high);
		int mid = (low + high) / 2;
		if (p > mid) {
			int x = getAns(mid, high);
			if (x == p) {
				low = mid;
			} else {
				high = mid;
			}
		} else {
			int x = getAns(low, mid);
			if (x == p) {
				high = mid;
			} else {
				low = mid;
			}
		}
	}
	if (high == low) {
		cout << "! " << low << endl;
	} else {
		int xx = getAns(low, high);
		cout << "! ";
		if (xx == low) cout << high << endl;
		else cout << low << endl;
	}

	return 0;
}