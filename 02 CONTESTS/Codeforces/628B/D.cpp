#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
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

    // 2 * (a & b) + (a ^ b) = (a + b)

    int xr, sum;
    cin >> xr >> sum;
    if (xr == 0 and sum == 0) {
        cout << 0 << endl;
    } else if (xr > sum) {
        cout << -1 << endl;
    } else if (xr % 2 != sum % 2) {
        cout << -1 << endl;
    } else if (sum == xr) {
        cout << 1 << endl;
        cout << sum << endl;
    } else {
        int a = (sum - xr) / 2;
        if ((a + xr) == (a ^ xr)) {
            cout << 2 << endl;
            cout << a << " " << a + xr << endl;
        } else {
            cout << 3 << endl;
            cout << a << " " << a << " " << xr << endl;
        }
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}