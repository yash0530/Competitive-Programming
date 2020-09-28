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

int binpow(int a, int b, int m) {
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

bool intersect(vector<int> a, vector<int> b) {
    if (b[1] >= a[1] and b[1] <= a[2]) {
        return true;
    }
    if (b[2] >= a[1] and b[2] <= a[2]) {
        return true;
    }
    return false;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        getMat(points, n, 3, 0);
        for (int i = 0; i < n; i++) {
            cin >> points[i][1] >> points[i][2] >> points[i][0];
        }

        sort(points.begin(), points.end());
        bool possible = true;

        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                if (points[i][0] == points[j][0]) {
                    if (intersect(points[i], points[j])) {
                        if (points[j - 1][0] == points[j][0]) {
                            if (intersect(points[j - 1], points[j])) {
                                possible = false;
                                break;
                            }
                        }
                    }
                }
            }
            if (!possible) break;
        }
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}