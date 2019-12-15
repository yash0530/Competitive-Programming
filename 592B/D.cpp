#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m) vector<vector<int>> x(n, vector<int> (m))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cina(x, n) vector<int> x(n); for (int i = 0; i < n; i++) cin >> x[i];
#define srt(x) sort(x.begin(), x.end())
#define rev(x) reverse(x.begin(), x.end())

int32_t main() {
    fastio;
    int n; cin >> n;
    getMat(colors, 3, n + 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> colors[i][j];
        }
    }

    bool possible = true;
    vector<int> edges[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        if (edges[a].size() > 2) {
            possible = false;
        }
        if (edges[b].size() > 2) {
            possible = false;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {

        int v = -1;
        for (int i = 1; i <= n; i++) {
            if (edges[i].size() == 1) {
                v = i;
                break;
            }
        }

        queue<pair<int, int>> Q;
        Q.push({ v, 1 });
        vector<int> marked(n + 1);
        marked[v] = true;
        vector<int> vertex_level(n + 1);
        vertex_level[1] = v;

        while (!Q.empty()) {
            auto p = Q.front(); Q.pop();
            int vertex = p.first, l = p.second;
            int count = 0;
            for (auto x : edges[vertex]) {
                if (!marked[x]) {
                    count++;
                    marked[x] = true;
                    vertex_level[l + 1] = x;
                    Q.push({ x, l + 1 });
                }
            }
        }

        vector<vector<int>> x = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {3, 1, 2}, {3, 2, 1}, {2, 3, 1}};
        int min_val = 1e18;
        int pattern = -1;
        for (int i = 0; i < 6; i++) {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                int color = x[i][((j - 1) % 3)];
                sum += colors[color - 1][vertex_level[j]];
            }
            if (sum < min_val) {
                min_val = sum;
                pattern = i;
            }
        }
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) {
            int vertex = vertex_level[i];
            res[vertex] = x[pattern][(i - 1) % 3];
        }
        cout << min_val << endl;
        for (int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        } cout << endl;
    }

    return 0;
}