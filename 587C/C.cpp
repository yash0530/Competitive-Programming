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

vector<int> intersection(vector<int> a, vector<int> b) {
    vector<int> inter(4);
    if (a[2] <= b[0] or a[0] >= b[2] or a[1] >= b[3] or a[3] <= b[1]) {
        return inter;
    } else {
        inter[0] = min(max(a[0], b[0]), max(a[2], b[2]));
        inter[2] = max(min(a[0], b[0]), min(a[2], b[2]));
        inter[1] = min(max(a[1], b[1]), max(a[3], b[3]));
        inter[3] = max(min(a[1], b[1]), min(a[3], b[3]));
    }
    return inter;
}

int area(vector<int> a) {
    return abs(a[2] - a[0]) * abs(a[3] - a[1]);
}

int32_t main() {
    fastio;
    getMat(rects, 3, 4, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> rects[i][j];
        }
    }
    vector<int> wb1 = intersection(rects[0], rects[1]);
    vector<int> wb2 = intersection(rects[0], rects[2]);
    vector<int> wb1b2 = intersection(wb1, wb2);
    if (area(rects[0]) > (area(wb1) + area(wb2) - area(wb1b2))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}