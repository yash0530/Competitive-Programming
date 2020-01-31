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

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> arr(n + 1);
    queue<pair<int, int>> E;
    queue<pair<int, int>> O;
    vector<bool> even_marked(n + 1);
    vector<bool> odd_marked(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] & 1) {
            O.push({ i, 0 });
            odd_marked[i] = true;
        } else { 
            E.push({ i, 0 });
            even_marked[i] = true;
        }
    }
    vector<vector<int>> graph(n + 1);
    vector<int> res(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (i + arr[i] <= n) {
            graph[i + arr[i]].push_back(i);
        }
        if (i - arr[i] >= 1) {
            graph[i - arr[i]].push_back(i);
        }
    }
    while (!E.empty()) {
        auto x = E.front(); E.pop();
        if (arr[x.first] & 1) {
            res[x.first] = x.second;
        }
        for (auto g : graph[x.first]) {
            if (!even_marked[g]) {
                even_marked[g] = true;
                E.push({ g, x.second + 1 });
            }
        }
    }
    while (!O.empty()) {
        auto x = O.front(); O.pop();
        if (!(arr[x.first] & 1)) {
            res[x.first] = x.second;
        }
        for (auto g : graph[x.first]) {
            if (!odd_marked[g]) {
                odd_marked[g] = true;
                O.push({ g, x.second + 1 });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    } cout << endl;
    return 0;
}