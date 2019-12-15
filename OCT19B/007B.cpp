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
#define pout cout << fixed << setprecision(10)

struct node {
    long value;
    long additional;
};

class SegmentTree {
    private:
        node *tree;
        long treeSize;
        long arrSize;

        long __query(long qLow, long qHigh, long low, long high, long pos) {
            // total overlap
            if (qLow <= low and qHigh >= high) {
                return tree[pos].value + (high - low + 1) * tree[pos].additional;
            }

            // no overlap
            else if (qLow > high or qHigh < low) {
                return 0;
            }

            // partial overlap
            else {
                long mid = (high + low) / 2;

                // taking care of additionals
                if (tree[pos].additional != 0) {
                    long add = tree[pos].additional;
                    tree[pos].value += (high - low + 1) * add;
                    tree[pos].additional = 0;
 
                    tree[2 * pos + 1].additional += add;
                    tree[2 * pos + 2].additional += add;
                }

                long left = __query(qLow, qHigh, low, mid, 2 * pos + 1);
                long right = __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
                return left + right;
            }
        }

        void __update(long qLow, long qHigh, long low, long high, long pos, long val) {
            // total overlap
            if (qLow <= low and qHigh >= high) {
                tree[pos].additional += val;
            }

            // no overlap
            else if (qLow > high or qHigh < low) {
                return;
            }

            // partial overlap
            else {
                long mid = (high + low) / 2;

                // taking care of additionals
                if (tree[pos].additional != 0) {
                    long add = tree[pos].additional;
                    tree[pos].additional = 0;

                    tree[2 * pos + 1].additional += add;
                    tree[2 * pos + 2].additional += add;
                }

                __update(qLow, qHigh, low, mid, 2 * pos + 1, val);
                __update(qLow, qHigh, mid + 1, high, 2 * pos + 2, val);
                tree[pos].value = tree[2 * pos + 1].value + tree[2 * pos + 2].value
                                    + (mid - low + 1) * tree[2 * pos + 1].additional 
                                    + (high - mid) * tree[2 * pos + 2].additional;
            }
        }

    public:
        SegmentTree(long n) {
            arrSize = n;
            treeSize = 2 * (1 << (int) ceil(log2(n))) - 1;

            tree = new node[treeSize];
            for (long i = 0; i < treeSize; i++) {
                tree[i].value = 0;
                tree[i].additional = 0;
            }
        }

        long _query(long qLow, long qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0);
        }

        void _update(long qLow, long qHigh, long val) {
            __update(qLow, qHigh, 0, arrSize - 1, 0, val);
        }
};

void dfs(vector<int> *e, vector<int> &dor, int s, vector<bool> &vis, vector<pair<int, int>> &st) {
    st[s].first = dor.size();
    dor.push_back(s);
    for (auto x : e[s]) {
        if (!vis[x]) {
            vis[x] = true;
            dfs(e, dor, x, vis, st);
        }
    }
    st[s].second = dor.size();
}

int32_t main() {
    fastio;

    // input
    int n, q;
    cin >> n >> q;
    vector<int> edges[n];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    // getting the depth of all vertices
    vector<int> depth(n);
    vector<bool> leaf(n);

    queue<pair<int, int>> Q;
    vector<bool> marked(n);
    Q.push({ 0, 0 });
    depth[0] = 0;
    marked[0] = true;
    while (!Q.empty()) {
        auto s = Q.front(); Q.pop();
        int v = s.first, d = s.second;
        int count = 0;
        for (auto x : edges[v]) {
            if (!marked[x]) {
                marked[x] = true;
                Q.push({ x, d + 1 });
                depth[x] = d + 1;
                count++;
            }
        }
        leaf[v] = !count;
    }

    // preprocessing queries
    // { E, time, stat, vertex, value (if applicable), ans }
    vector<vector<int>> queries;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        queries.push_back({ -1 * depth[i], 0, '+', i, x });
    }

    for (int i = 1; i <= q; i++) {
        char x; cin >> x;
        if (x == '+') {
            int v, k; cin >> v >> k; v--;
            queries.push_back({ i - depth[v], i, x, v, k });
        } else if (x == '?') {
            int v; cin >> v; v--;
            queries.push_back({ i - depth[v], i, x, v });
        }
    }
    sort(queries.begin(), queries.end());

    // getting dfs order
    vector<int> dfs_order;
    vector<pair<int, int>> sub_trees(n);
    vector<bool> visited(n); visited[0] = true;
    dfs(edges, dfs_order, 0, visited, sub_trees);

    // solving queries for non - leaf vertices
    //   0  1     2     3       4
    // { E, time, stat, vertex, value / ans }
    SegmentTree nonLeafSegTree(n);
    int curr = queries[0][0];
    for (int i = 0; i < (int) queries.size(); i++) {
        if (curr == queries[i][0]) {
            if (queries[i][2] == 43) {
                nonLeafSegTree._update(sub_trees[queries[i][3]].first, sub_trees[queries[i][3]].second - 1, queries[i][4]);
            } else if (!leaf[queries[i][3]]) {
                queries[i].push_back(nonLeafSegTree._query(sub_trees[queries[i][3]].first, sub_trees[queries[i][3]].first));
            }
        } else {
            // rollback queries
            int j = --i;
            while (j >= 0 and queries[j][0] == curr) {
                if (queries[j][2] == 43) {
                    nonLeafSegTree._update(sub_trees[queries[j][3]].first, sub_trees[queries[j][3]].second - 1, -1 * queries[j][4]);
                }
                j--;
            }
            curr = queries[i + 1][0];
        }
    }

    // solving queries for leaf vertices
    SegmentTree leafSegTee(n);
    for (int i = 0; i < (int) queries.size(); i++) {
        if (queries[i][2] == 43) {
            leafSegTee._update(sub_trees[queries[i][3]].first, sub_trees[queries[i][3]].second - 1, queries[i][4]);
        } else if (leaf[queries[i][3]]) {
            queries[i].push_back(leafSegTee._query(sub_trees[queries[i][3]].first, sub_trees[queries[i][3]].first));
        }
    }

    // print res
    vector<pair<bool, int>> res(n + q + 1, { 0, 0 });
    for (int i = 0; i < (int) queries.size(); i++) {
        if (queries[i][2] == 63) {
            res[queries[i][1]].first = true;
            res[queries[i][1]].second = queries[i][4];
        }
    }
    for (auto x : res) {
        if (x.first) {
            cout << x.second << endl;
        }
    }

    return 0;
}