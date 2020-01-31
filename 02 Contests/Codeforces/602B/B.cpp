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
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        vector<int> res(n);
        bool possible = true;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (s.find(x) != s.end()) {
                res[i] = x;
                s.erase(x);
            } else {
                auto it = s.lower_bound(x);
                if (it == s.begin()) {
                    possible = false;
                } else {
                    it--;
                    res[i] = *it;
                    s.erase(it);
                }
            }
        }
        if (possible) {
            for (int i = 0; i < n; i++) {
                cout << res[i] << " ";
            } cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}