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

int32_t main() { 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int res = 2 * (pow(10, n));
        int a, b, d;
        cin >> a;
        cout << res + a << endl;
        fflush(stdout);
        cin >> b;
        cout << (int) pow(10, n) - b << endl;
        fflush(stdout);
        cin >> d;
        cout << (int) pow(10, n) - d << endl;
        fflush(stdout);
        cin >> d;
    }
    return 0;
}