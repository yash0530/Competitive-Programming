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

int32_t main() { fastio;
    int t; cin >> t;
    while(t--) {
    	int m, n; cin >> m >> n;
    	char x;
    	vector<pair<int, int>> ends(m, { -1, -1 });
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			cin >> x;
    			if (x == 'P') {
    				if (ends[i].first == -1) {
	    				ends[i].first = j;
    				}
    				ends[i].second = j;
    			}
    		}
    	}
    	int ans = 0;
    	int level = 0, loc = -1;
    	while (level < m) {
    		if (ends[level].first == -1) {
    			level++;
    		} else {
    			if (level & 1) {
    				loc = ends[level].second;
    			} else {
    				loc = ends[level].first;
    			}
    			break;
    		}
    	}
    	while (level < m) {
    		int next = level + 1;
    		while (next < m) {
    			if (ends[next].first == -1) {
    				next++;
    			} else {
    				break;
    			}
    		}

    		if (next == m) {
    			if (level & 1) {
    				ans += loc - ends[level].first;
    			} else {
    				ans += ends[level].second - loc;
    			}
    		} else {
    			if ((level & 1) != (next & 1)) {
	    			if (level & 1) {
	    				ans += loc - min(ends[level].first, ends[next].first) + (next - level);
	    				loc = min(ends[level].first, ends[next].first);
	    			} else {
	    				ans += max(ends[level].second, ends[next].second) - loc + (next - level);
	    				loc = max(ends[level].second, ends[next].second);
	    			}
	    		} else {
	    			if (level & 1) {
	    				ans += loc - ends[level].first + (next - level);
	    				ans += abs(ends[next].second - ends[level].first);
	    				loc = ends[next].second;
	    			} else {
	    				ans += ends[level].second - loc + (next - level);
	    				ans += abs(ends[next].first - ends[level].second);
	    				loc = ends[next].first;
	    			}
	    		}
    		}
    		level = next;
    	}
    	cout << ans << endl;
    }
    return 0;
}
