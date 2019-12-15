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
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        int e1 = 0, o1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            o1 += arr[i] & 1;
            e1 += !(arr[i] & 1);
        }
        int m; cin >> m;
        int e2 = 0, o2 = 0;
        vector<int> arr2(m);
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
            o2 += arr2[i] & 1;
            e2 += !(arr2[i] & 1);
        }
        cout << e1 * e2 + o1 * o2 << endl;
    }
    return 0;
}