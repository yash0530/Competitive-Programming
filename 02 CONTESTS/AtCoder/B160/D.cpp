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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++) {
    	adj[i].push_back(i + 1);
    	adj[i + 1].push_back(i);
    }
    adj[x].push_back(y);
    adj[y].push_back(x);

    vector<int> res(n);
    for (int i = 1; i <= n; i++) {
    	vector<bool> marked(n + 1);
    	queue<pair<int, int>> Q;
    	Q.push({ i, 0 });
    	marked[i] = true;
    	while (!Q.empty()) {
    		int x = Q.front().first; y = Q.front().second;
    		Q.pop();
    		res[y]++;
    		for (auto u : adj[x]) {
    			if (!marked[u]) {
    				marked[u] = true;
    				Q.push({ u, y + 1 });
    			}
    		}
    	}
    }
    for (int i = 1; i < n; i++) {
    	cout << res[i] / 2 << endl;
    }

    return 0;
}