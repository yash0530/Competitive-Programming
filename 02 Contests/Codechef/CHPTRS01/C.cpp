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
    while (t--) {
    	int n; cin >> n;
    	string s; cin >> s;
    	int d, x; cin >> d;
    	set<int> np;
    	vector<int> curr;
    	for (int i = 0; i < n; i++) {
    		if (s[i] == '1') {
    			curr.push_back(i);
    		}
    	} 
    	for (int i = 0; i < d; i++) {
    		cin >> x;
    		np.insert(--x);
    		vector<int> nw;
    		for (auto c : curr) {
    			if (np.find(c) != np.end()) {
    				if ((c != n - 1) and s[c + 1] == '0') {
    					if (np.find(c + 1) == np.end()) {
    						nw.push_back(c + 1);
    						s[c + 1] = '1';
    					}
    				}
    			} else {
    				if ((c != n - 1) and s[c + 1] == '0') {
    					if (np.find(c + 1) == np.end()) {
    						nw.push_back(c + 1);
    						s[c + 1] = '1';
    					}
    				}
    				if (c != 0 and s[c - 1] == '0') {
						nw.push_back(c - 1);
						s[c - 1] = '1';
    				}
    			}
    		}
    		curr = nw;
    	}
    	int count = 0;
    	for (auto x : s) {
    		count += x - '0';
    	}
    	cout << count << endl;
    }
    return 0;
}
