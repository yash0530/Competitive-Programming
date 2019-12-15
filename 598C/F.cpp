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
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int inversions(string s, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[i]) {
                count++;
            }
        }
    }
    return count;
}

int32_t main() { fastio;
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> sf(128), tf(128);
        for (auto x : s) {
            sf[x]++;
        }
        for (auto x : t) {
            tf[x]++;
        }
        bool found = false, possible = true;
        for (int i = 0; i < 128; i++) {
            if (sf[i] != tf[i]) {
                possible = false;
                break;
            }
            if (sf[i] > 1) {
                found = true;
            }
        }
        if (!possible) {
            cout << "NO" << endl;
        } else if (found) {
            cout << "YES" << endl;
        } else {
            int inv1 = inversions(s, n);
            int inv2 = inversions(t, n);
            if ((inv1 & 1) == (inv2 & 1)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}