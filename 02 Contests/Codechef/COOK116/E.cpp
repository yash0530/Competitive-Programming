#include <bits/stdc++.h>
using namespace std;

int getDist(int node) {
    cout << 1 << " " << node << endl;
    fflush(stdout);
    cin >> node; return node;
}

int getNode(int node, int dist) {
    cout << 2 << " " << node << " " << dist << endl;
    fflush(stdout);
    cin >> node; return node;
}

int printRes(int node) {
    cout << 3 << " " << node << endl;
    fflush(stdout);
    cin >> node; return node;
}

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int h; cin >> h;
        int leaf = getNode(1, h);
        for (int i = 0; i < h; i++) {
            leaf = getNode(leaf, getDist(leaf));
        }
        printRes(leaf);
    }
    return 0;
}