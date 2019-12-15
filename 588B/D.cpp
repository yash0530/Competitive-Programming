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

int32_t main() {
    fastio;
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    unordered_map<int, int> H;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        H[a[i].first]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    vector<int> unique;
    for (auto x : H) {
        if (x.second > 1) {
            unique.push_back(x.first);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (auto u : unique) {
            if (u == (u | a[i].first)) {
                res += a[i].second;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}