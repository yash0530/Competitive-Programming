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
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int get(int i, int j) {
    cout << 1 << " " << i << " " << j << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

void BS(int i, int low, int high, int start, pair<int, int> &res) {
    if (low > high) {
        return;
    }
    int mid = (low + high) / 2;
    int x = get(i, mid);
    if (start == x) {
        res = { mid, x };
        return BS(i, low, mid - 1, start, res);
    } else {
        return BS(i, mid + 1, high, start, res);
    }
}

int32_t main() {
    int n; cin >> n;
    vector<int> wts(n + 1), vals(n + 1);
    int index = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        pair<int, int> x;
        BS(i, index, index + 99, get(i, index + 99), x);
        wts[i] = x.first - index + 1;
        vals[i] = x.second - sum;
        sum += vals[i];
        index = x.first + 1;
    }
    cout << 2 << endl;
    for (int i = 1; i <= n; i++) {
        cout << wts[i] << " ";
    } cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << vals[i] << " ";
    } cout << endl;
    return 0;
}