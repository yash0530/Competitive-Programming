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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, { 0, 0, 0 });
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    vector<int> rel(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        rel[b] = max(rel[b], a);
    }
    vector<priority_queue<int>> locs(n);
    for (int i = 0; i < n; i++) {
        if (rel[i] != -1) {
            locs[rel[i]].push(arr[i][2]);
        }
    }
    priority_queue<int, vector<int>, greater<int>> castles;
    int army = k;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (army + castles.size() < arr[i][0]) {
            possible = false;
            break;
        }
        while (army < arr[i][0]) {
            castles.pop();
            army++;
        }
        army += arr[i][1];
        if (rel[i] == -1 and army > 0) {
            army--;
            castles.push(arr[i][2]);
        }
        while (army > 0 and !locs[i].empty()) {
            int x = locs[i].top(); locs[i].pop();
            army--;
            castles.push(x);
        }
        if (army == 0 and !locs[i].empty() and !castles.empty()) {
            while (!locs[i].empty()) {
                if (locs[i].top() > castles.top()) {
                    castles.pop();
                    castles.push(locs[i].top());
                    locs[i].pop();
                } else {
                    break;
                }
            }
        }
    }
    if (possible) {
        int res = 0;
        while (!castles.empty()) {
            res += castles.top();
            castles.pop();
        }
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}