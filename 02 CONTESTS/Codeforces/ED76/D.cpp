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
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> monsters(n);
        for (int i = 0; i < n; i++) {
            cin >> monsters[i];
        }
        int m; cin >> m;
        vector<int> best(n + 1);
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            best[b] = max(best[b], a);
        }
        for (int i = n - 1; i > 0; i--) {
            best[i] = max(best[i], best[i + 1]);
        }

        int days = 0, i = 0;
        while (i < n) {
            days++;
            if (monsters[i] > best[1]) {
                days = -1;
                break;
            }
            int j = 1, worst = monsters[i];
            while (i < n and worst <= best[j]) {
                i++; j++;
                if (i < n) worst = max(worst, monsters[i]);
            }
        }
        cout << days << endl;
    }
    return 0;
}