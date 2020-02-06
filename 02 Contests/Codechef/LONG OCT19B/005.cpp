#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int a, b;
        int edges[n + 1];
        int odd = 0;
        memset(edges, 0, sizeof edges);
        vector<int> graph[n + 1];
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            edges[a]++; edges[b]++;

            graph[b].push_back(a);
            graph[a].push_back(b);

            if (edges[a] % 2 == 0) {
                odd--;
            } else {
                odd++;
            }

            if (edges[b] % 2 == 0) {
                odd--;
            } else {
                odd++;
            }
        }

        if (m % 2 == 0) {
            cout << 1 << endl;
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            } cout << endl;
        } else {

            if (odd == 0) {
                cout << 3 << endl;
                int count = 2;
                int neigh = -1;
                for (int i = 1; i <= n; i++) {
                    if (count == 2 and edges[i] > 0) {
                        cout << count << " ";
                        count++;
                        neigh = graph[i][0];
                    } else if (count == 3 and neigh == i) {
                        cout << count << " ";
                        count++;
                    } else {
                        cout << 1 << " ";
                    }
                }
                cout << endl;

            } else {
                cout << 2 << endl;
                int count = 1;
                for (int i = 1; i <= n; i++) {
                    if (i != 1 and count == 1 and edges[i] % 2 == 1) {
                        cout << 2 << " ";
                        count++;
                    } else {
                        cout << 1 << " ";
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}