#include <bits/stdc++.h>
using namespace std;

#define INF (int) 9e18
#define int long long

// ------------------ ORDERED_SET --------------------- //

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// ------------------------- SEED -------------------- //
// srand(chrono :: steady_clock :: now().time_since_epoch().count());

int getRand() {
    int a = rand();
    int b = rand();
    return a * (RAND_MAX + 1) + b;
}

struct Edge {
    int v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

// ------------------------------- factors ---------------- //

vector<int> getFactors(int n) {
    vector<int> factors = { 1 };
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

// --------------------------- prime factors --------------- //

vector<int> primeFactors(int n) {
    vector<int> factorization = { 1 };
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (int d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    } return true;
}

int lcm(int a, int b) {
    return (int) (((double) a  / __gcd(a, b)) * b);
}

int lcmArray(vector<int> arr) {
    if (arr.size() == 1) return arr[0];
    int ans = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}

// ---------------------------- LIS ----------------------------- //
int CeilIndex(vector<int>& v, int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key) {
            r = m;
        } else {
            l = m;
        }
    }
    return r; 
}

// returns array of indices
vector<int> LIS(vector<int>& v) {
    int n = v.size();
    vector<int> tail(n, 0), tail_index(n, -1), res(n, -1);
    int length = 1;
    tail[0] = v[0];
    tail_index[0] = 0;
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0]) {
            tail[0] = v[i];
            tail_index[0] = i;
        } else if (v[i] > tail[length - 1]) {
            tail[length++] = v[i];
            tail_index[length - 1] = i;
            res[i] = tail_index[length - 2];
        } else {
            int x = CeilIndex(tail, -1, length - 1, v[i]);
            tail[x] = v[i];
            tail_index[x] = i;
            if (x) res[i] = tail_index[x - 1];
        }
    }
    
    // return length; 
    vector<int> lis;
    int x = tail_index[length - 1];
    while (res[x] != -1) {
        lis.push_back(x);
        x = res[x];
    }
    lis.push_back(x);
    reverse(lis.begin(), lis.end());
    return lis;
}

// ----------------------- Floyd Warshall ------------------- //

for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

// ------------------------ Dijkstra ----------------------- //
vector<int> dijkstra(int x, int n, vector<vector<Edge>> adj) {

    vector<int> distance(n + 1);
    vector<bool> processed(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (int i = 1; i <= n; i++) {
        distance[i] = INF;
    }

    distance[x] = 0;
    q.push({ 0, x });

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.v, w = u.weight;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({ distance[b], b });
            }
        }
    }

    return distance;
}

// ----------------- Bellmon Ford ------------------------ //

int32_t main() {
    int n = 5;
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < 6; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }
    auto d = dijkstra(1, n, adj);
    for (auto x : d) {
        cout << x << endl;
    }
}

// --------------------- BINARY LIFTING ----------------------- //
int timer;
const int LG = 22, maxN = 1e5 + 5;
int tin[maxN], tout[maxN];
int up[maxN][LG + 1];
vector<int> adj[maxN];

void dfs(int v = 1, int p = 1) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= LG; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return (tin[u] <= tin[v]) and (tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = LG; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

// ----------------- TOPO SORT ------------------- //
void topoDFS(int v, vector<bool> &visited, vector<int> &res) {
    visited[v] = true;
    for (auto a : adj[v]) {
        if (!visited[a]) {
            topoDFS(a, visited, res); 
        }
    }
    res.pb(v);
}

vector<int> topoSort() {
    vector<int> res; 
    vector<bool> visited(n + 5);
    for (int i = 1; i <= n; i++) { 
        if (!visited[i]) { 
            topoDFS(i, visited, res); 
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// ------------------------ DIRECTED HAS CYCLE --------- //
bool cycleDFS(int v, vector<bool> &visited, vector<bool> &recStack) { 
    if(!visited[v]) {
        visited[v] = true; 
        recStack[v] = true;
        for(auto a : adj[v]) { 
            if (!visited[a] and cycleDFS(a, visited, recStack)) {
                return true; 
            }
            else if (recStack[a]) {
                return true; 
            }
        }
    }
    recStack[v] = false;
    return false; 
}

bool hasCycle() {
    vector<bool> visited(n + 5), recStack(n + 5);
    for(int i = 1; i <= n; i++) {
        if (cycleDFS(i, visited, recStack)) {
            return true; 
        }
    }
    return false; 
}

// ----------------------- DFS ORDERING ------------------ //
int location;
pii dfsM[maxN];
// set location to -1 before dfs call
// dfs ordering
void dfs(int u = 1, int p = 1) {
    dfsM[u].fs = ++location;
    for (auto x : adj[u]) {
        if (x != p) {
            dfs(x, u);
        }
    }
    dfsM[u].sc = location;
}