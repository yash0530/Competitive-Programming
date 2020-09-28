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
        string s; cin >> s;
        int l = 0, r = 0, u = 0, d = 0;
        for (auto x : s) {
            l += x == 'L';
            r += x == 'R';
            u += x == 'U';
            d += x == 'D';
        }
        int a = min(l, r);
        int b = min(u, d);
        int c = min({ l, r, u, d });
        if (c > 0) {
            string res ="";
            int alpha = b / 2;
            int beta = b - alpha;
            for (int i = 0; i < alpha; i++) {
                res += 'U';
            }
            for (int i = 0; i < a; i++) {
                res += 'R';
            }
            for (int i = 0; i < b; i++) {
                res += 'D';
            }
            for (int i = 0; i < a; i++) {
                res += 'L';
            }
            for (int i = 0; i < beta; i++) {
                res += 'U';
            }
            cout << res.size() << endl;
            cout << res << endl;
        } else if (a > 0) {
            cout << 2 << endl;
            cout << "LR" << endl;
        } else if (b > 0) {
            cout << 2 << endl;
            cout << "UD" << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}