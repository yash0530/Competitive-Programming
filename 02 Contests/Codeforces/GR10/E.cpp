#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() {
    int n; cin >> n;
    int base = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int here = 1;
            for (int j = 0; j < n; j++) {
                cout << base * here << " ";
                here *= 2;
            } cout << endl;
            base *= 4;
        } else {
            for (int j = 0; j < n; j++) {
                cout << 0 << " ";
            } cout << endl;
        }
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << 1 << " " << 1 << endl;
        x >>= 1;
        int col = 1, row = 1;
        for (int i = 0; i < 2 * (n - 1); i++) {
            if (x & (1LL << i)) {
                if (row & 1) {
                    col++;
                    cout << row << " " << col << endl;
                } else {
                    row++;
                    cout << row << " " << col << endl;
                }
            } else {
                if (row & 1) {
                    row++;
                    cout << row << " " << col << endl;
                } else {
                    col++;
                    cout << row << " " << col << endl;
                }
            }
        }
    }
    return 0;
}