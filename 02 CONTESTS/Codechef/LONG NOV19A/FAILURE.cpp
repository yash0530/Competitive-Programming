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
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

class WeightedUF {
    private:
        int vertices;
        int *arr;
        int *size;

        int __root(int a) {
            while (arr[a] != a) {
                arr[a] = arr[arr[a]];
                a = arr[a];
            }
            return a;
        }

    public:
        WeightedUF(int v) {
            vertices = v;
            arr = new int[v + 1];
            size = new int[v + 1];
            for (int i = 1; i <= v; i++) {
                size[i] = 1;
                arr[i] = i;
            }
        }

        void _union(int a, int b) {
            int rootA = __root(a);
            int rootB = __root(b);

            if (rootA == rootB) return;
            
            if (size[rootA] < size[rootB]) {
                arr[rootA] = rootB;
                size[rootB] += size[rootA];
            } else {
                arr[rootB] = rootA;
                size[rootA] += size[rootB];
            }
        }

        bool _find(int a, int b) {
            return arr[__root(a)] == arr[__root(b)];
        }
};

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n, m, count = 0;
        cin >> n >> m;
        WeightedUF master(n);
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].first >> edges[i].second;
            if (master._find(edges[i].first, edges[i].second)) {
                count++;
            }
            master._union(edges[i].first, edges[i].second);
        }
        if (count > 0) {
            bool possible = false; int ans = -1;
            for (int i = 1; i <= n; i++) {
                WeightedUF child(n);
                int child_count = 0;
                for (int j = 0; j < m; j++) {
                    if (edges[j].first != i and edges[j].second != i) {
                        if (child._find(edges[j].first, edges[j].second)) {
                            child_count++;
                        }
                        child._union(edges[j].first, edges[j].second);
                    }
                }
                if (child_count == 0) {
                    possible = true;
                    ans = i;                    
                    break;
                }
            }
            if (possible) {
                cout << ans << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}