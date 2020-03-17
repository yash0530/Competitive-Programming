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

    int n; cin >> n;
    string s; cin >> s;
    int o = 0, c = 0;
    for (auto x : s) {
        o += x == ')';
        c += x == '(';
    }
    if (o != c) {
        cout << -1 << endl;
    } else {
        int valid = true, len = 0, count = 0, res = 0;
        for (auto x : s) {
            len++;
            count += x == ')';
            count -= x == '(';
            if (count > 0) {
                valid = false;
            }
            if (count == 0 and valid) {
                len = 0;
            } else if (count == 0) {
                valid = true;
                res += len;
                len = 0;
            }
        }
        cout << res << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}