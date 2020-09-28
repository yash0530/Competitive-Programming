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
        int n, m;
        cin >> n >> m;
        getMat(a, n, m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int res = n * m;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                int left = i - 1, right = i + 1, top = j - 1, bottom = j + 1;
                while (left >= 0 and right < n and top >= 0 and bottom < m) {
                    if (a[left][j] == a[right][j] and a[i][top] == a[i][bottom]) {
                        left--;
                        right++;
                        top--;
                        bottom++;
                        res++;
                    } else {
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}