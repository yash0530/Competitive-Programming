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
        vector<int> mp(26);
        string s; cin >> s;
        int n = s.length();
        string temp = "";
        for (int i = 0; i < n; i++) {
            if (i == n - 1 or s[i] != s[i + 1]) {
                temp.push_back(s[i]);
            } else {
                i++;
            }
        }
        set<char> res;
        for (auto t : temp) {
            res.insert(t);
        }
        for (auto r : res) {
            cout << r;
        }
        cout << endl;
    }
    return 0;
}