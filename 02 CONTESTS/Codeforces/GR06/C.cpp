#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    int r, c;
    cin >> r >> c;
    bool inverted = false;
    if (r > c) {
        swap(r, c);
        inverted = true;
    }
    if (r == 1 and c == 1) {
        cout << 0 << endl;
    } else {
        getMat(res, r, c, 0);
        for (int i = 1, row = 0; i <= r; i++, row++) {
            for (int j = r + 1, col = 0; j <= c + r; j++, col++) {
                res[row][col] = i * j;
            }
        }
        if (inverted) {
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < r; j++) {
                    cout << res[j][i] << " ";
                } cout << endl;
            }
        } else {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cout << res[i][j] << " ";
                } cout << endl;
            }
        }
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}