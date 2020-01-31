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
#define pout cout << fixed << setprecision(1)

#define k 30

int getMin(vector<vector<int>> &mn, vector<int> &log, int l, int r) {
    if (l >= r) return mn[l][0];
    int j = log[r - l + 1];
    return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}

int getMax(vector<vector<int>> &mx, vector<int> &log, int l, int r) {
    if (l >= r) return mx[l][0];
    int j = log[r - l + 1];
    return max(mx[l][j], mx[r - (1 << j) + 1][j]);
}

#define MAXN 1e5 + 5

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    getMat(mx, MAXN, k + 5, 0);
    getMat(mn, MAXN, k + 5, 0);

    for (int i = 0; i < n; i++)
        mx[i][0] = arr[i];

    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            mx[i][j] = max(mx[i][j-1], mx[i + (1 << (j - 1))][j - 1]);

    for (int i = 0; i < n; i++)
        mn[i][0] = arr[i];

    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            mn[i][j] = min(mn[i][j-1], mn[i + (1 << (j - 1))][j - 1]);

    vector<int> log(MAXN + 1);
    log[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        log[i] = log[i/2] + 1;

    int q, l, r; cin >> q;
    while (q--) {
        cin >> l >> r;
        int minimum = getMin(mn, log, l, r);
        int maximum = getMax(mx, log, l, r);
        int M = 0;
        if (l != 0) {
            M = getMax(mx, log, 0, l - 1);
        }
        if (r != n - 1) {
            M = max(M, getMax(mx, log, r + 1, n - 1));
        }
        pout << (double) (minimum + max((double) (maximum - minimum) / 2, (double) (M))) << endl;
    }
    return 0;
}