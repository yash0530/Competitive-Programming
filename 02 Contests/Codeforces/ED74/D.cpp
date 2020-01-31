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
    int n; cin >> n;
    string s; cin >> s;
    int good = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            int j = i + 1;
            while (s[j] == 'B') j++;
            if (i != j - 1) {
                good -= j - i - 2;
                i = j - 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            int j = i + 1;
            while (s[j] == 'A') j++;
            if (i != j - 1) {
                good -= j - i - 2;
                i = j - 1;
            }
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == 'A') {
            int j = i - 1;
            while (s[j] == 'B') j--;
            if (i != j + 1) {
                good -= i - j - 1;
                i = j + 1;
            }
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == 'B') {
            int j = i - 1;
            while (s[j] == 'A') j--;
            if (i != j + 1) {
                good -= i - j - 1;
                i = j + 1;
            }
        }
    }
    cout << good << endl;
    return 0;
}