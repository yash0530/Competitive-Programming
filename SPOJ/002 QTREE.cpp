#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

// SegmentTree => 0 Indexed
// Graph => 0 Indexed

class SegmentTree {
    private:
        int treeSize, arrSize;
        vector<int> tree;

        int __query(int qLow, int qHigh, int low, int high, int pos) {
            if (qLow <= low and qHigh >= high) {
                return tree[pos];
            }
            if ((qLow > high) or (qHigh < low)) {
                return 0;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            int leftVal = __query(qLow, qHigh, low, mid, left);
            int rightVal = __query(qLow, qHigh, mid + 1, high, right);
            return max(leftVal, rightVal);
        }

        void __update(int qLow, int qHigh, int low, int high, int pos, int val) {
            if (qLow <= low and qHigh >= high) {
                tree[pos] = val;
                return;
            }
            if ((qLow > high) or (qHigh < low)) {
                return;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            __update(qLow, qHigh, low, mid, left, val);
            __update(qLow, qHigh, mid + 1, high, right, val);
            tree[pos] = max(tree[left], tree[right]);
        }

        void __build(vector<int> arr, int pos, int low, int high) {
            if (low == high) {
                tree[pos] = arr[low];
            } else {
                int mid = (low + high) / 2;
                int left = pos * 2 + 1;
                int right = pos * 2 + 2;

                __build(arr, left, low, mid);
                __build(arr, right, mid + 1, high);
                tree[pos] = max(tree[left], tree[right]);
            }
        }

    public:
        SegmentTree() {}

        void _build(vector<int> arr) {
            arrSize = arr.size();
            treeSize = 4 * arrSize;
            tree.resize(treeSize);
            __build(arr, 0, 0, arrSize - 1);
        }

        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0);
        }

        void _update(int qLow, int qHigh, int val) {
            __update(qLow, qHigh, 0, arrSize - 1, 0, val);
        }
};

class Graph {
    private:
        int n;
        vector<vector<pair<int, int>>> adj;

        // LCA
        int l, timer;
        vector<vector<int>> up;
        vector<int> tin, tout;

        // HLD
        // ptr -> current size of baseArray
        // posInBase -> denotes position of vertex in baseArray
        vector<int> depth, subsize;
        int chainNo, ptr;
        vector<int> chainInd, chainHead, posInBase, baseArray;
        SegmentTree segTree;

        // specific to this problem only
        // otherEnd -> maps index of edge to vertex
        int index = 0; // iddex for edge
        vector<int> otherEnd;
        vector<vector<int>> edgeIndex;

        void __depthFirstSearch(int v, int p, int d) {
            tin[v] = ++timer;
            up[v][0] = p;

            depth[v] = d;
            subsize[v] = 1;

            for (int i = 1; i <= l; ++i) {
                up[v][i] = up[up[v][i-1]][i-1];
            }
            
            for (int i = 0; i < (int) adj[v].size(); i++) {
                if (adj[v][i].first != p) {

                    // problem specific
                    // edgeIndex is mapped to lower vertex
                    otherEnd[edgeIndex[v][i]] = adj[v][i].first;
                    
                    __depthFirstSearch(adj[v][i].first, v, d + 1);
                    subsize[v] += subsize[adj[v][i].first];
                }
            }
            tout[v] = ++timer;
        }

        int __queryHLD(int u, int v) {
            if (u == v) return 0;
            int uchain, vchain = chainInd[v], ans = -1;

            while (true) {
                uchain = chainInd[u];
                if (uchain == vchain) {
                    if (u == v) break;
                    int res = segTree._query(posInBase[v] + 1, posInBase[u]);
                    ans = max(res, ans);
                    break;
                }
                int res = segTree._query(posInBase[chainHead[uchain]], posInBase[u]);
                ans = max(res, ans);
                u = chainHead[uchain];
                u = up[u][0]; // move to its parent meaning chaning chains
            }
            return ans;
        }

    public:
        Graph(int vertex) {
            n = vertex;
            l = ceil(log2(n));
            adj.assign(n, vector<pair<int, int>>());

            // HLD
            chainHead.resize(n, -1);
            chainInd.resize(n);
            posInBase.resize(n);
            baseArray.resize(n);
            chainNo = 0, ptr = 0;

            // problem specific
            otherEnd.resize(n);
            edgeIndex.assign(n, vector<int>());
        }

        void _addEdge(int a, int b, int w) {
            adj[a].push_back({ b, w });
            adj[b].push_back({ a, w });

            // problem specific
			edgeIndex[a].push_back(index);
            edgeIndex[b].push_back(index);
            index++;
        }

        bool _isAncestor(int u, int v) {
            return (tin[u] <= tin[v]) and (tout[u] >= tout[v]);
        }

        void _preProcess(int root) {
            // LCA
            tin.resize(n);
            tout.resize(n);
            timer = 0;
            up.assign(n, vector<int>(l + 1));

            // HLD
            depth.resize(n);
            subsize.resize(n);
            
            // LCA and HLD
            __depthFirstSearch(root, root, 0);
        }

        int _LCA(int u, int v) {
            if (_isAncestor(u, v)) {
                return u;
            }
            if (_isAncestor(v, u)) {
                return v;
            }
            for (int i = l; i >= 0; --i) {
                if (!_isAncestor(up[u][i], v)) {
                    u = up[u][i];
                }
            }
            return up[u][0];
        }

        void _HLD(int v, int cost, int p) {
            if (chainHead[chainNo] == -1) {
                chainHead[chainNo] = v;
            }
            chainInd[v] = chainNo;
            posInBase[v] = ptr;
            baseArray[ptr++] = cost;

            int sc = -1, ncost;
            for(auto u : adj[v]) {
                if(u.first != p) {
                    if((sc == -1) or (subsize[sc] < subsize[u.first])) {
                        sc = u.first;
                        ncost = u.second;
                    }
                }
            }
            if(sc != -1) {
                _HLD(sc, ncost, v);
            }

            for(auto u : adj[v]) {
                if(u.first != p and sc != u.first) {
                    chainNo++;
                    _HLD(u.first, u.second, v);
                }
            }
        }

        void _setupSegTree() {
            segTree._build(baseArray);
        }

        int _queryHLD(int a, int b) {
            int lca = _LCA(a, b);
            return max(__queryHLD(a, lca), __queryHLD(b, lca));
        }

        void _updateHLD(int a, int b) {
            int loc = posInBase[otherEnd[a]];
            segTree._update(loc, loc, b);
        }
};

int main() {
    int t; scanf("%d ", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int a, b, w;
        Graph G(n);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d %d", &a, &b, &w);
            G._addEdge(--a, --b, w);
        }
        
        G._preProcess(0);
        G._HLD(0, -1, 0);
        G._setupSegTree();

        char s[100]; scanf("%s", s);
        while (s[0] != 'D') {
            if (s[0] == 'Q') {
                scanf("%d %d", &a, &b);
                int x = G._queryHLD(--a, --b);
                printf("%d\n", x);
            } else {
                scanf("%d %d", &a, &b);
                G._updateHLD(--a, b);
            }
            scanf("%s", s);
        }
    }
    return 0;
}