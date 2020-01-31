#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define int long long
#define uint unsigned long long
#define MOD (int) (1e9 + 7)
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    } return res;
}

vector<int> I(31);
vector<int> Ibar(31);

void solve(int bit, vector<int> arr) {
    if (bit < 0 or arr.size() == 0) return;
    int zero = 0, one = 0;
    vector<int> x, y;
    for (auto a : arr) {
        if ((1 << bit) & a) {
            x.push_back(a);
            one++;
            Ibar[bit] += zero;
        } else {
            y.push_back(a);
            zero++;
            I[bit] += one;
        }
    }
    solve(bit - 1, x);
    solve(bit - 1, y);
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        I = vector<int>(31);
        Ibar = vector<int>(31);
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(30, arr);
        while (q--) {
            int k; cin >> k;
            int res = 0;
            for (int bit = 0; bit < 31; bit++) {
                if ((1 << bit) & k) {
                    res += Ibar[bit];
                } else {
                    res += I[bit];
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}