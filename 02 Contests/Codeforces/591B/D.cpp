#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define MOD (int) (1e9 + 7)
#define int long long
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

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n;
        map<int, int> first;
        map<int, int> last;
        set<int> unique;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (first.find(x) == first.end()) {
                first[x] = i;
            }
            last[x] = i;
            unique.insert(x);
        }
        vector<int> uq(unique.begin(), unique.end());
        int global_max = 1, curr = 1;
        for (int i = 0; i < uq.size() - 1; i++) {
            if (first[uq[i + 1]] > last[uq[i]]) {
                curr++;
            } else {
                curr = 1;
            }
            global_max = max(curr, global_max);
        }
        cout <<  uq.size() - global_max << endl;
    }
    return 0;
}