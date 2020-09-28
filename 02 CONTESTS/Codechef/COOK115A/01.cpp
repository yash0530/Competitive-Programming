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
        int n; cin >> n;
        vector<int> a(n), b(n), res(n);
        map<int, int> freq;
        int x = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x ^= a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            freq[b[i]]++;
            x ^= b[i];
        }
        bool possible = true;
        for (int i = 0; i < n; i++) {
            int y = x ^ a[i];
            if (!freq[y]) {
                possible = false;
                break;
            } else {
                res[i] = y;
                freq[y]--;
            }
        }
        if (!possible) {
            cout << -1 << endl;
        } else {
            for (auto r : res) {
                cout << r << " ";
            } cout << endl;
        }
    }
    return 0;
}