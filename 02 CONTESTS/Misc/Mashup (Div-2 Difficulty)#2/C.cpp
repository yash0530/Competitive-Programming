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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    set<int> adj[26];
    for (int i = 0; i < n; i++) {
    	if (a[i] != b[i]) {
    		adj[a[i] - 'a'].insert(b[i] - 'a');
    		adj[b[i] - 'a'].insert(a[i] - 'a');
    	}
    }
    vector<pair<char, char>> p;
    vector<bool> marked(26);
    for (int i = 0; i < 26; i++) {
    	if (!marked[i]) {
    		queue<int> Q;
    		marked[i] = true;
    		Q.push(i);
    		while (!Q.empty()) {
    			int x = Q.front(); Q.pop();
    			for (auto y : adj[x]) {
    				if (!marked[y]) {
    					marked[y] = true;
    					p.push_back({ y + 'a', x + 'a' });
    					Q.push(y);
    				}
    			}
    		}
    	}
    }
    cout << p.size() << endl;
    for (auto x : p) {
    	cout << x.first << " " << x.second << endl;
    }
    return 0;
}
