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

namespace minn {
 
    int n;
    vector< vector<int> > table;
    vector<int> LOG;
 
    void build(vector<int> arr) {
        n = size(arr);
        LOG.clear();
        LOG.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            LOG[i] = !(i & (i - 1)) + LOG[i - 1];
        }
        int lg = LOG[n] + 1;
        table.clear();
        table.assign(n, vector<int>(lg));
        for (int j = 0; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                if (j == 0) {
                    table[i][j] = arr[i];
                } else {
                    table[i][j] = table[i][j - 1] < table[i + (1 << (j - 1))][j - 1] ? 
                                    table[i][j - 1] : table[i + (1 << (j - 1))][j - 1];
                }
            }
        }
    }
 
    int query(int low, int high) {
        int k = LOG[high - low + 1];
        return table[low][k] < table[high - (1 << k) + 1][k] ? 
                table[low][k] : table[high - (1 << k) + 1][k];
    }
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		// minn::build(arr);
		// int low = 0, high = n - 1;
		// vector<int> res;
		// int loc = 1;
		// while (low <= high) {
		// 	if (arr[low] == loc) {
		// 		if (minn::query(low + 1, high) > loc) {
		// 			res.pb(1);	
		// 		} else {
		// 			break;
		// 		}
		// 		low++;
		// 	} else if (arr[high] == loc) {
		// 		if (minn::query(low, high - 1) > loc) {
		// 			res.pb(1);
		// 		} else {
		// 			break;
		// 		}
		// 		high--;
		// 	} else {
		// 		if (minn::query(low, high) == loc) {
		// 			res.pb(1);
		// 			loc++;
		// 		}
		// 		break;
		// 	}
		// 	loc++;
		// }
		// sort(_all(arr));
		// bool poss = true;
		// for (int i = 0; i < n; i++) {
		// 	if ((i + 1) != arr[i]) {
		// 		poss = false;
		// 	}
		// }
		// reverse(_all(res));
		// if (size(res) == n) {
		// 	for (auto r : res) {
		// 		cout << r;
		// 	} cout << endl;
		// } else {
		// 	cout << poss;
		// 	for (int i = 0; i < (n - 1 - size(res)); i++) {
		// 		cout << 0;
		// 	}
		// 	for (auto r : res) {
		// 		cout << r;
		// 	} cout << endl;
		// }
	}
	return 0;
}