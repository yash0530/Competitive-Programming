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
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    int k; cin >> k;
    while (k--) {
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        string ss, tt;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                ss.push_back(s[i]);
                tt.push_back(t[i]);
            }
        }
        if (ss.size() == 0) {
            cout << "Yes" << endl;
        } else if (ss.size() != 2) {
            cout << "No" << endl;
        } else {
            if (ss[0] == ss[1] and tt[0] == tt[1]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}