#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

class WeightedUF {
    private:
        vector<int> arr;
        vector<int> size;

        int __root(int a) {
            while (arr[a] != a) {
                arr[a] = arr[arr[a]];
                a = arr[a];
            }
            return a;
        }

    public:
        WeightedUF(int v) {
            arr = vector<int>(v + 1);
            size = vector<int>(v + 1);
            for (int i = 0; i <= v; i++) {
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
            return __root(a) == __root(b);
        }
};

int32_t main() {
    int n;
    vector<Edge> edges;
    
    // initialize edges and n

    vector<Edge> mst; int cost = 0;
    WeightedUF uf(n);
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        if (!uf._find(e.u, e.v)) {
            cost += e.weight;
            mst.push_back(e);
            uf._union(e.u, e.v);
        }
    }

    return 0;
}