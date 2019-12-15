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

int binpow(int a, int b, int m) {
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
        int num; cin >> num;
        string x = to_string(num);
        int len = x.length();
        int min_elem = 1e18;
        for (int i = 1; i <= len; i++) {
            string s = to_string(num);
            string res = s.substr(0, i - 1) + s.substr(i, len - i);
            int num = stoi(res);
            min_elem = min(min_elem, num);
        }
        cout << min_elem << endl;
    }
    return 0;
}