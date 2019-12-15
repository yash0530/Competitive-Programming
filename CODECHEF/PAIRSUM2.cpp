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
#define pout cout << fixed << setprecision(10)

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, q, a, b; cin >> n >> q;
        vector<int> B(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> B[i];
        }
        vector<int> p1(n), p2(n);
        int sign = -1;
        p1[0] = 0;
        p2[0] = 0;
        for (int i = 1; i < n; i++) {
            p1[i] = sign * B[i - 1] + p1[i - 1];
            sign *= -1;
            p2[i] = sign * B[i - 1] + p2[i - 1];
        }
        while (q--) {
            cin >> a >> b;
            int r = max(a, b), l = min(a, b);
            if ((r - l) % 2 == 0) {
                cout << "UNKNOWN" << endl;
            } else {
                if (l % 2 == 0) {
                    cout << p1[r - 1] - p1[l - 1] << endl;
                } else {
                    cout << p2[r - 1] - p2[l - 1] << endl;
                }
            }
        }
    }
    return 0;
}