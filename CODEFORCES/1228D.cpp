#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MOD (int) (1e9 + 7)

int fastpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fastio;
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> color(n + 1);
    vector<bool> marked(n + 1);
    bool possible = true;
    vector<int> sizes(4);
    for (int i = 1; i <= n; i++) {
        if (!marked[i]) {
            marked[i] = true;
            color[i] = 1;
            sizes[1]++;

            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int parent = Q.front(); Q.pop();
                for (auto x : edges[parent]) {
                    if (!marked[x]) {
                        if (color[parent] == 1) {
                            color[x] = 2;
                            marked[x] = true;
                            Q.push(x);
                        } else {
                            color[x] = 1;
                            marked[x] = true;
                            Q.push(x);
                        }
                        sizes[color[x]]++;
                    } else {
                        if (color[x] == color[parent]) {
                            color[x]++;
                            if (color[x] > 3) {
                                possible = false;
                                break;
                            }
                            sizes[color[x] - 1]--;
                            sizes[color[x]]++;
                            Q.push(x);
                        }
                    }
                }
                if (!possible) {
                    break;
                }
            }
            if (!possible) {
                break;
            }
        }
    }

    if (possible) {
        if (sizes[1] == 0 or sizes[2] == 0 or sizes[3] == 0) {
            possible = false;
        } else {
            for (int i = 1; i <= n; i++) {
                vector<int> szs(4);
                for (auto x : edges[i]) {
                    szs[color[x]]++;
                }
                if (color[i] == 1) {
                    if (sizes[2] != szs[2] or sizes[3] != szs[3]) {
                        possible = false;
                        break;
                    }
                } else if (color[i] == 2) {
                    if (sizes[1] != szs[1] or sizes[3] != szs[3]) {
                        possible = false;
                        break;
                    }
                } else {
                    if (sizes[2] != szs[2] or sizes[1] != szs[1]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
    }

    if (possible) {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " ";
        } cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}