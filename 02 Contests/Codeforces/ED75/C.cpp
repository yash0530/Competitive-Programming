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
#define MOD (int) (1e9 + 7)

int fastpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        string c1, c2;
        for (auto x : s) {
            if (x & 1) {
                c1.push_back(x);
            } else {
                c2.push_back(x);
            }
        }

        int i = 0, j = 0;
        while (i < c1.length() and j < c2.length()) {
            if (c1[i] < c2[j]) {
                cout << c1[i]; i++;
            } else {
                cout << c2[j]; j++;
            }
        }
        while (i < c1.length()) {
            cout << c1[i]; i++;
        }
        while (j < c2.length()) {
            cout << c2[j]; j++;
        }
        cout << endl;
    }
    return 0;
}