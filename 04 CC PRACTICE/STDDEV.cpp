#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m) vector<vector<int>> x(n, vector<int> (m))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sq 1.22474487139

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        if (n == 1 and s != 0) {
            cout << -1 << endl;
            n--;
        } else if (n == 1) {
            cout << 0 << endl;
            n--;
        } else if (n & 1) {
            cout << setprecision(10) << sq * s << " " << -1 * sq * s << " " << 0 << " ";
            n -= 3;
        }
        for (int i = 0; 2 * i < n; i++) {
            cout << -1 * s << " ";
        }
        for (int i = 0; 2 * i < n; i++) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}