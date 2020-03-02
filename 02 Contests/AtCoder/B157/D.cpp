#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

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

        bool _union(int a, int b) {
            int rootA = __root(a);
            int rootB = __root(b);

            if (rootA == rootB) return false;
            
            if (size[rootA] < size[rootB]) {
                arr[rootA] = rootB;
                size[rootB] += size[rootA];
            } else {
                arr[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            return true;
        }

        bool _find(int a, int b) {
            return __root(a) == __root(b);
        }
};

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> friends(n + 5);
    vector<pair<int, int>> blocks(k);

    WeightedUF uf(n);
    vector<int> res(n + 5);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
        uf._union(a, b);
    }

    vector<int> marked(n + 5);
    vector<int> marked2(n + 5);
    for (int i = 1; i <= n; i++) {
        if (!marked[i]) {
            int count = 0;
            queue<int> Q;
            Q.push(i);
            marked[i] = true;
            while (!Q.empty()) {
                int val = Q.front(); Q.pop();
                for (auto v : friends[val]) {
                    if (!marked[v]) {
                        count++;
                        Q.push(v);
                        marked[v] = true;
                    }
                }
            }

            queue<int> Q2;
            Q2.push(i);
            marked2[i] = true;
            while (!Q2.empty()) {
                int val = Q2.front(); Q2.pop();
                res[val] += count - friends[val].size();
                for (auto v : friends[val]) {
                    if (!marked2[v]) {
                        Q2.push(v);
                        marked2[v] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        if (uf._find(a, b)) {
            res[a]--;
            res[b]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    } cout << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}