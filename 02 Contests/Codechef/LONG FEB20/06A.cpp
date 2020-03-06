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

int dfs(int s, int p, vector<vector<int>> &edges, vector<int> &legs, vector<int> &strokes, vector<int> &valid) {
    int res = 0;
    legs.push_back(valid[s]);
    strokes.push_back(0);
    for (auto v : edges[s]) {
        if (v != p) {
            vector<int> vlegs, vstrokes;
            res += dfs(v, s, edges, vlegs, vstrokes, valid);

            // get res from legs
            vlegs.push_back(0);
            int i = vlegs.size() - 1, j = strokes.size() - 1;
            while (i >= 0 and j >= 0) {
                res += vlegs[i] * strokes[j];
                i--; j--;
            }

            // get res from strokes
            vstrokes.pop_back();
            i = legs.size() - 1, j = vstrokes.size() - 1;
            while (i >= 0 and j >= 0) {
                res += legs[i] * vstrokes[j];
                i--; j--;
            }

            // find additional strokes
            vector<int> additional_strokes(min(legs.size(), vlegs.size()));
            i = legs.size() - 1, j = vlegs.size() - 1;
            int k = min(i, j);
            while (i >= 0 and j >= 0) {
                additional_strokes[k] = legs[i] * vlegs[j];
                i--; j--; k--;
            }

            // adding additional strokes to strokes
            if (additional_strokes.size() > strokes.size()) {
                i = strokes.size() - 1, j = additional_strokes.size() - 1;
                while (i >= 0 and j >= 0) {
                    additional_strokes[j] += strokes[i];
                    i--; j--;
                }
                strokes = additional_strokes;
            } else {
                i = strokes.size() - 1, j = additional_strokes.size() - 1;
                while (i >= 0 and j >= 0) {
                    strokes[i] += additional_strokes[j];
                    i--; j--;
                }
            }

            // adding vstrokes to strokes
            if (vstrokes.size() > strokes.size()) {
                i = strokes.size() - 1, j = vstrokes.size() - 1;
                while (i >= 0 and j >= 0) {
                    vstrokes[j] += strokes[i];
                    i--; j--;
                }
                strokes = vstrokes;
            } else {
                i = strokes.size() - 1, j = vstrokes.size() - 1;
                while (i >= 0 and j >= 0) {
                    strokes[i] += vstrokes[j];
                    i--; j--;
                }
            }

            // adding legs
            if (vlegs.size() > legs.size()) {
                i = vlegs.size() - 1, j = legs.size() - 1;
                while (i >= 0 and j >= 0) {
                    vlegs[i] += legs[j];
                    i--; j--;
                }
                legs = vlegs;
            } else {
                i = legs.size() - 1, j = vlegs.size() - 1;
                while (i >= 0 and j >= 0) {
                    legs[i] += vlegs[j];
                    i--; j--;
                }
            }
        }
    }
    return res;
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
        vector<int> legs, strokes;
        cout << dfs(1, -1, edges, legs, strokes, valid) * 6 << endl;
    }
    return 0;
}