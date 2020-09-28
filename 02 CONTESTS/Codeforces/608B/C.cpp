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
    int n, x, y;
    cin >> n >> x >> y;
    int a, b;
    vector<int> res(4);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > x) {
            res[0]++;
        }
        if (b < y) {
            res[1]++;
        }
        if (a < x) {
            res[2]++;
        }
        if (b > y) {
            res[3]++;
        }
    }
    int mx = *max_element(res.begin(), res.end());
    cout << mx << endl;
    if (mx == res[0]) {
        cout << x + 1 << " " << y << endl;
    } else if (mx == res[1]) {
        cout << x << " " << y - 1 << endl;
    } else if (mx == res[2]) {
        cout << x - 1 << " " << y << endl;
    } else if (mx == res[3]) {
        cout << x << " " << y + 1 << endl;
    }
    return 0;
}