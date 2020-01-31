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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int x;
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> x;
            pos[x] = i;
        }
        int pos_max = pos[1], pos_min = pos[1];
        string s = "1";
        for (int i = 2; i <= n; i++) {
            pos_max = max(pos_max, pos[i]);
            pos_min = min(pos_min, pos[i]);
            if (pos_max - pos_min + 1 == i) {
                s.push_back('1');
            } else {
                s.push_back('0');
            }
        }
        cout << s << endl;
    }
    return 0;
}