#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int count(vector<int> arr) {
    int len = arr.size();
    if (len < 3) return 0;

    vector<int> prefix(len);
    prefix[len - 1] = arr[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        prefix[i] = arr[i] + prefix[i + 1];
    }

    vector<int> p(len);
    for (int i = len - 2; i >= 0; i--) {
        p[i] = arr[i] * prefix[i + 1];
    }
    prefix[len - 1] = 0;
    for (int i = len - 2; i >= 0; i--) {
        prefix[i] = p[i] + prefix[i + 1];
    }

    p = vector<int>(len);
    for (int i = len - 3; i >= 0; i--) {
        p[i] = arr[i] * prefix[i + 1];
    }
    int sum = 0;
    for (auto x : p) sum += x;
    return sum * 6;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n;
        vector<vector<int>> edges(n + 1);
        vector<int> valid(n + 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            cin >> valid[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (edges[i].size() > 2) {
                vector<int> marked(n + 1);
                queue<pair<int, int>> Q;
                int max_depth = 0;
                vector<vector<int>> levels(edges[i].size());
                for (int j = 0; j < edges[i].size(); j++) {
                    int source = edges[i][j];
                    Q.push({ source, 0 });
                    marked[source] = true;
                    while (!Q.empty()) {
                        int curr = Q.front().first;
                        int dist = Q.front().second;
                        Q.pop();
                        if (valid[curr]) {
                            max_depth = max(max_depth, dist + 1);
                            if (levels[j].size() <= dist) {
                                while (levels[j].size() < dist) {
                                    levels[j].push_back(0);
                                }
                                levels[j].push_back(1);
                            } else {
                                levels[j][dist]++;
                            }
                        }
                        for (auto x : edges[curr]) {
                            if (!marked[x] and i != x) {
                                Q.push({ x, dist + 1 });
                                marked[x] = true;
                            }
                        }
                    }
                    
                }
                for (int x = 0; x < max_depth; x++) {
                    vector<int> arr;
                    for (int j = 0; j < levels.size(); j++) {
                        if (levels[j].size() > x) {
                            arr.push_back(levels[j][x]);
                        }
                    }
                    res += count(arr);
                }
            }
        }
        cout << count({ 4, 3, 5, 4 }) / 6 << endl;
        cout << res / 6 << endl;
    }
    return 0;
}