#include <bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << endl
using namespace std;

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q; cin >> n >> q;
    int a, b;
    vector<int> edges[n + 1];
    int vals[n + 1];
    int update[n + 1];
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
    }

    for (int j = 0; j < q; j++) {
        memset(update, 0, sizeof update);
        queue<int> Q;
        Q.push(1);
        bool marked[n + 1];
        memset(marked, false, sizeof marked);
        marked[1] = true;

        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (auto x : edges[v]) {
                if (!marked[x]) {
                    update[x] = vals[v];
                    Q.push(x);
                    marked[x] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i != 1 and edges[i].size() == 1) {
                vals[i] += update[i];
            } else {
                vals[i] = update[i];
            }
        }

        char stat; cin >> stat;
        if (stat == '+') {
            int v, k;
            cin >> v >> k;
            vals[v] += k;
        } else {
            int v; cin >> v;
            cout << vals[v] << endl;
        }
    }

    return 0;
}