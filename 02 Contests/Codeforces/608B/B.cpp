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
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int32_t main() { fastio;
    int n; cin >> n;
    int b = 0, w = 0;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        w += s[i] == 'W';
        b += s[i] == 'B';
    }
    if (!w or !b) {
        cout << 0 << endl;
    } else if (w & 1 and b & 1) {
        cout << -1 << endl;
    } else if (!(w & 1)) {
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'W') {
                s[i] = 'B';
                s[i + 1] = s[i + 1] == 'B' ? 'W' : 'B';
                res.push_back(i + 1);
            }
        }
        cout << res.size() << endl;
        for (auto r : res) {
            cout << r << " ";
        } cout << endl;
    } else {
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'B') {
                s[i] = 'W';
                s[i + 1] = s[i + 1] == 'B' ? 'W' : 'B';
                res.push_back(i + 1);
            }
        }
        cout << res.size() << endl;
        for (auto r : res) {
            cout << r << " ";
        } cout << endl;
    }
    return 0;
}