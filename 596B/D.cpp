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
    int n, k, x;
    cin >> n >> k;
    int result = 0;
    map<vector<pair<int, int>>, int> divisors;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vector<pair<int, int>> d;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                int count = 0;
                while (x % i == 0) {
                    x /= i;
                    count++;
                } 
                d.push_back({ i, count });
            }
        }
        if (x > 1) {
            d.push_back({ x, 1 });
        }
        sort(d.begin(), d.end());
        for (auto &x : d) {
            x.second = x.second % k;
        }
        vector<pair<int, int>> divs;
        vector<pair<int, int>> reqd;
        for (auto x : d) {
            if (x.second) {
                divs.push_back(x);
                reqd.push_back({ x.first, k - x.second });
            }
        }
        result += divisors[reqd];
        divisors[divs]++;
    }
    cout << result << endl;
    return 0;
}