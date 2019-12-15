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
    int n, m; cin >> n >> m;
    getMat(mat, n, m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = n - 2; i >= 1; i--) {
        for (int j = m - 2; j >= 1; j--) {
            if (mat[i][j] == 0) {
                mat[i][j] = min(mat[i + 1][j], mat[i][j + 1]) - 1;
            }
        }
    }
    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] <= mat[i][j - 1] or mat[i][j] <= 0) {
                possible = false;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (mat[i][j] <= mat[i - 1][j] or mat[i][j] <= 0) {
                possible = false;
                break;
            }
        }
    }
    if (possible) {
        int sum = 0;
        for (auto x : mat) {
            sum += accumulate(x.begin(), x.end(), 0);
        }
        cout << sum << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}