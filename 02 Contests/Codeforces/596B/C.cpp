#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define int long long
#define uint unsigned long long
#define MOD (int) (1e9 + 7)
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    } return res;
}

int32_t main() {
    fastio;
    int n, p;
    cin >> n >> p;
    int count = -1;
    for (int i = 1; i <= 31; i++) {
        int x = n - i * p;
        if (__builtin_popcount(x) <= i and x >= i) {
            count = i;
            break;
        }
    }
    cout << count << endl;
    return 0;
}