#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 1e9
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
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

const int maxN = 205;
int dist[maxN][maxN], graph[maxN][maxN];

void solve() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> B(L);
    for (int i = 0; i < L; i++) {
        cin >> B[i];
    }
    int u, v, w;
    memset(graph, 0, sizeof graph);
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else if (graph[i][j]) {
                dist[i][j] = graph[i][j];
            } else {
                dist[i][j] = INF;
            }
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<pair<int, int>> used;
    int prev = 0, curr = 1, till = 0;
    while (curr < L) {
        if (dist[B[prev]][B[curr]] < (till + graph[B[curr - 1]][B[curr]])) {
            if (prev + 1 == curr) {
                cout << -1 << endl;
                return;
            }
            used.push_back({ prev, curr - 1 });
            prev = curr - 1;
            till = 0;
        } else {
            till += graph[B[curr - 1]][B[curr]];
            curr++;
        }
    }
    cout << used.size() + 2 << endl;
}

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}