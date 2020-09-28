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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = a + b + c + d;
    vector<int> res(n + 1);
    int start = 0;
    if (abs((a + c) - (b + d)) > 1) {
        cout << "NO" << endl;
    } else {
        for (int i = 0, j = 2 * a + 1; i < c; i++, j += 2) {
            res[j] = 2;
        }
        if ((b + d) <= (a + c)) {
            start = 2;
        }
        for (int i = 0, j = start; i < b; i++, j += 2) {
            res[j] = 1;
        }
        for (int i = 0, j = 2 * b + start; i < d; i++, j += 2) {
            res[j] = 3;
        }
        start /= 2;
        bool poss = true;
        for (int i = start + 1; i < n + start; i++) {
            if (abs(res[i] - res[i - 1]) > 1) {
                poss = false;
                break;
            }
        }
        if (poss) {
            cout << "YES" << endl;
            for (int i = start; i < n + start; i++) {
                cout << res[i] << " ";
            } cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}