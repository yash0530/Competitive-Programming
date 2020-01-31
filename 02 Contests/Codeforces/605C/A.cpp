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
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        if (a[0] != a[1]) {
            a[0]++;
        } else if (a[1] != a[2]) {
            a[0]++;
            a[1]++;
        }

        if (a[1] != a[2]) {
            a[2]--;
        } else if (a[1] != a[0]) {
            a[2]--;
            a[1]--;
        }
        cout << abs(a[0] - a[1]) + abs(a[1] - a[2]) + abs(a[0] - a[2]) << endl;
    }
    return 0;
}