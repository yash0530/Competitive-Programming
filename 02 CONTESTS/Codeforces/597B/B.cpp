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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string str; cin >> str;
        int r = 0, p = 0, s = 0;
        for (int i = 0; i < (int) str.length(); i++) {
            r += str[i] == 'R';
            p += str[i] == 'P';
            s += str[i] == 'S';
        }
        int res = min(a, s) + min(b, r) + min(c, p);
        if (res >= (int) ceil((double) n / 2.0)) {
            cout << "YES" << endl;
            string temp = "";
            for (auto x : str) {
                if (x == 'R' and b > 0) {
                    temp.push_back('P');
                    b--;
                } else if (x == 'S' and a > 0) {
                    temp.push_back('R');
                    a--;
                } else if (x == 'P' and c > 0) {
                    temp.push_back('S');
                    c--;
                } else {
                    temp.push_back('#');
                }
            }
            for (auto &t : temp) {
                if (t == '#') {
                    if (a > 0) {
                        t = 'R';
                        a--;
                    } else if (b > 0) {
                        t = 'P';
                        b--;
                    } else {
                        t = 'S';
                        c--;
                    }
                }
            }
            cout << temp << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}