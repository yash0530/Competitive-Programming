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

string n; int len;

int count(int k, int edge, int index) {
    if (index == len) {
        return k == 0;
    }
    if (k) {
        if (edge) {
            if (n[index] == '0') {
                return count(k, edge, index + 1);
            }
            int res = count(k - 1, 0, index + 1) * (n[index] - '0' - 1);
            res += count(k - 1, edge, index + 1);
            res += count(k, 0, index + 1);
            return res;
        } else {
            return count(k - 1, edge, index + 1) * 9 + count(k, edge, index + 1);
        }
    } else {
        return count(k, edge, index + 1);
    }
}

int32_t main() { fastio;
    time_t start = now();

    int k;
    cin >> n >> k;
    len = n.size();
    cout << count(k, 1, 0) << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}