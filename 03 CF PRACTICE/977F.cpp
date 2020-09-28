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

int32_t main() { fastio;
    time_t start = now();

    int n, x; cin >> n;
    map<int, int> M;
    vector<pair<int, int>> dp(n, { 1, -1 });
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (M.find(x - 1) != M.end()) {
            dp[i] = { dp[M[x - 1]].first + 1, M[x - 1] };
        }
        if (M.find(x) == M.end()) {
            M[x] = i;
        } else if (dp[M[x]].first < dp[i].first) {
            M[x] = i;
        }
    }

    // recovering solution
    auto m = max_element(dp.begin(), dp.end());
    int index = m - dp.begin();
    pair<int, int> pr = *m;
    cout << pr.first << endl;

    vector<int> res;
    while (index != -1) {
        res.push_back(index + 1);
        index = pr.second;
        pr = dp[index];
    }

    reverse(res.begin(), res.end());
    for (auto r : res) {
        cout << r << " ";
    } cout << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}