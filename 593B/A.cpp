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

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (2 * b <= c) {
            cout << b + (2 * b) << endl;
        } else {
            int s = (c / 2) + (c / 2) * 2;
            b -= (c / 2);
            if (2 * a <= b) {
                cout << a + (2 * a) + s << endl;
            } else {
                s += (b / 2) + (b / 2) * 2;
                cout << s << endl;
            }
        }
    }
    return 0;
}