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

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        uint l, r;
        cin >> l >> r;
        bitset<64> L(l), R(r);
        string a = L.to_string(), b = R.to_string();
        string res = "";
        int loc;
        for (int i = 0; i < 64; i++) {
            if (a[i] == b[i]) {
                res.push_back(b[i]);
            } else {
                loc = i;
                break;
            }
        }
        for (int i = loc; i < 64; i++) {
            res.push_back('1');
        }
        bitset<64> RES(res);
        uint x = RES.to_ullong();
        cout << x << endl;
    }
    return 0;
}