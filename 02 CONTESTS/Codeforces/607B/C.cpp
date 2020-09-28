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
        int x; cin >> x;
        string s; cin >> s;
        int res = s.length();
        int i = 0;
        while (s.length() < x) {
            int y = s.length() - i - 1;
            if ((s[i] - '0' - 1) >= 1) {
                s +=  s.substr(i + 1, y);
            }
            if ((s[i] - '0' - 1) == 2) {
                s +=  s.substr(i + 1, y);
            }
            i++;
        }
        for (int i = 0; i < x; i++) {
            res = (res % HELL + ((res - i - 1 + HELL) % HELL * (int) (s[i] - '0' - 1)) % HELL) % HELL;
        }
        cout << res << endl;
    }
    return 0;
}