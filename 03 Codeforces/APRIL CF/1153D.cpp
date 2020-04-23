#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb emplace_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)

int n, p, k;
const int maxN = 3e5 + 5;
int fns[maxN], dp[maxN];
vector<int> adj[maxN];

void dfs(int root = 1, int parent = 1) {
    if (size(adj[root]) == 1 and root != parent) {
        dp[root] = 1; k++;
        return;
    }
    if (fns[root]) {
        dp[root] = INF;
    } else {
        dp[root] = 0;
    }
    for (auto x : adj[root]) {
        if (x != parent) {
            dfs(x, root);
            if (fns[root]) {
                dp[root] = min(dp[root], dp[x]);
            } else {
                dp[root] += dp[x];
            }
        }
    } 
}

int32_t main() { fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)  {
        cin >> fns[i];
    }    
    for (int i = 2; i <= n; i++) {
        cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    dfs();
    cout << k + 1 - dp[1] << endl;
    return 0;
}
