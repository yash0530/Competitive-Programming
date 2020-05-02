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

const int maxN = 55, maxK = 35;
int n, k, p;
int arr[maxN][maxK];
vector<vector<int>> dp;

int res(int index, int plates) {
    if (plates == 0) {
        return 0;
    }
    if (index == n) {
        return -INF;
    }
    if (dp[index][plates] != -1) {
        return dp[index][plates];
    }
    int count = 0;
    for (int i = 0; i <= min(plates, k); i++) {
        if (i == 0) {
            count = max(count, res(index + 1, plates));
        } else {
            count = max(count, arr[index][i - 1] + res(index + 1, plates - i));
        }
    }
    dp[index][plates] = count;
    return count;
}

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    for (int i = 0; i < t; i++) {

        cin >> n >> k >> p;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
            for (int j = 1; j < k; j++) {
                arr[i][j] += arr[i][j - 1];
            }
        }
        dp = vector<vector<int>> (n + 2, vector<int>(p + 2, -1));
        cout << "Case #" << i + 1 << ": " << res(0, p) << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}