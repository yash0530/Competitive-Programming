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
    while (n--) {
        string s; cin >> s;
        int len = s.length();
        if (s.substr(len - 2, 2).compare("po") == 0) {
            cout << "FILIPINO" << endl;
        } else {
            string x = s.substr(len - 4, 4);
            if (x.compare("desu") == 0 or x.compare("masu") == 0) {
                cout << "JAPANESE" << endl;
            } else {
                cout << "KOREAN" << endl;
            }
        }
    }
    return 0;
}