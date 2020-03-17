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

void relax(vector<int> &res) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = i + 1; i < res.size(); i++) {
            if ((res[i] + res[j]) == (res[i] xor res[j])) {
                vector<int> res2 = { res[i] + res[j] };
                for (int k = 0; k < res.size(); k++) {
                    if (i != k and j != k) {
                        res2.push_back(res[k]);
                    }
                }
                res = res2;
                return;
            }
        }
    }
}

int32_t main() { fastio;
    time_t start = now();

    int xr, sum;
    cin >> xr >> sum;
    if (xr > sum) {
        cout << -1 << endl;
    } else {
        int num = 0, base = 1;
        int x = xr, y = sum;
        while (x and y) {
            num += base * ((x % 2) & (y % 2));
            x /= 2;
            y /= 2;
            base *= 2;
        }
        x = xr - num;
        y = sum - num - x;
        vector <int> res;
        if (y % 2 == 0) {
            if (y == 0 and num == 0 and x == 0) {
                res = {};
            } else if (num == 0 and y == 0) {
                res = { x };
            } else if (y == 0) {
                res = { num, x };
            } else if (num == 0) {
                res = { x, y / 2, y / 2 };
            } else {
                res = { num, x, y / 2, y / 2 };
            }
            relax(res);relax(res);relax(res);
            cout << res.size() << endl;
            for (auto r : res) {
                cout << r << " ";
            } cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}