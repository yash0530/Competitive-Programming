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
        vector<vector<int>> mat(n, vector<int>(n));
        if (n == 1) {
            cout << "Hooray" << endl;
            cout << 1 << endl;
        } else if (n & 1) {
            cout << "Boo" << endl;
        } else {
            cout << "Hooray" << endl;
            for (int i = 0; i < n; i++) {
                mat[i][i] = n;
            }
            int col = 1;
            for (int i = 1; i < n; i++) {
                int tcol = col;
                for (int j = 0; j < n; j += 2) {
                    tcol = tcol % n;
                    mat[j][tcol] = i;
                    tcol += 2;
                }
                col++;
            }
            col = 2;
            for (int i = n + 1; i < 2 * n; i++) {
                int tcol = col;
                for (int j = 1; j < n; j += 2) {
                    tcol = tcol % n;
                    mat[j][tcol] = i;
                    tcol += 2;
                }
                col++;
            }
            for (auto x : mat) {
                for (auto y : x) {
                    cout << y << " ";
                } cout << endl;
            }
        }
    }
    return 0;
}