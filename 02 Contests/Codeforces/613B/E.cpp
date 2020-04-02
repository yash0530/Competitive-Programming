#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

int comp(vector<int> a, vector<int> b) {
	if (a[0] == b[0]) {
		return a[1] > b[1];
	} return a[0] < b[0];
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	int n, u, v; cin >> n;
    	vector<vector<int>> arr, ps;
    	vector<int> res(n, 0), lfs(n, 0);
    	map<int, int> lefts;

    	vector<bool> same(n);
    	map<pair<int, int>, int> present;
    	for (int i = 0; i < n; i++) {
    		cin >> u >> v;
    		ps.push_back({ u, v, i });
    		lefts[u]++;
    		arr.push_back({ u, 1, i });
			arr.push_back({ v, 2, i });

			if (present.find({ u, v }) != present.end()) {
				same[present[{ u, v }]] = true;
				same[i] = true;
			} 
			present[{ u, v }] = i;
    	}
    	sort(arr.begin(), arr.end());

    	set<vector<int>> open;
    	for (auto a : arr) {
    		if (a[1] == 1) {
    			if ((open.size() == 1)) {
    				auto s = *open.begin();
    				res[s[2]]++;
    			}
    			open.insert(a);
    		} else {
    			open.erase({ ps[a[2]][0], 1, a[2] });
    		}
    	}

    	sort(ps.begin(), ps.end(), comp);

    	int count = 0, back = -INF;
    	for (auto p : ps) {
    		if (back < p[0]) {
    			count++;
    			if (lefts[p[0]] == 1) {
    				lfs[p[2]] = 1;
    			}
    			back = max(back, p[1]);
    		}
			back = max(back, p[1]);
    	}

    	int mx = 0;
    	for (int i = 0; i < n; i++) {
			if (!same[i]) {
    			mx = max(mx, res[i] - lfs[i]);
    		}
    	}
    	cout << mx + count << endl;
    }
    return 0;
}
