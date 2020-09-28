#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int n, x; 
const int maxN = 1e5 + 5;
int dp[maxN];

int32_t main() { fastio;
    time_t start = now();
    cin >> n; dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        vector<int> divs;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                divs.push_back(j);
                if (j *j != x) {
                    divs.push_back(x / j);
                }
            }
        }
        sort(divs.rbegin(), divs.rend());
        for (auto d : divs) {
            if (d <= i) {
                dp[d] = (dp[d] + dp[d - 1]) % HELL;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + dp[i]) % HELL;
    }
    cout << res << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}