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
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> res(n);
        vector<bool> marked(n);
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                marked[i] = true;
                vector<int> chain;
                int loc = i;
                while (true) {
                    marked[loc] = true;
                    chain.push_back(loc);
                    if (i + 1 == arr[loc]) {
                        break;
                    }
                    loc = arr[loc] - 1;
                }
                int ans = chain.size();
                for (auto x : chain) {
                    res[x] = ans;
                }
            }
        }
        for (auto r : res) {
            cout << r << " ";
        } cout << endl;
    }
    return 0;
}