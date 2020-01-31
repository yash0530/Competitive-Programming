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
string getStr(int n) {
    string s;
    while (n != 0) {
        s.push_back('0' + (n % 3));
        n /= 3;
    }
    return s;
}

bool possible(int n) {
    string s;
    while (n != 0) {
        s.push_back('0' + (n % 3));
        n /= 3;
    }
    for (auto x : s) {
        if (x == '2') {
            return false;
        }
    }
    return true;
}

int32_t main() {
    fastio;
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        while (true) {
            if (possible(n)) {
                break;
            } else {
                n++;
            }
        }
        deb(getStr(n));
        cout << n << endl;
    }
    return 0;
}