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
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int n, h, l, r;
vector<int> arr;

getMat(dp, 2005, 2005, -1);

int res(int index, int start) {
    if (index == n) {
        return 0;
    }
    if (dp[index][start] != -1) {
        return dp[index][start];
    }
    int a = (start + arr[index]) % h;
    int x;
    if (l <= a and a <= r) {
        x = res(index + 1, a) + 1;
    } else {
        x = res(index + 1, a);
    }
    int b = (start + arr[index] - 1) % h;
    int y;
    if (l <= b and b <= r) {
        y = res(index + 1, b) + 1;
    } else {
        y = res(index + 1, b);
    }
    dp[index][start] = max(x, y);
    return max(x, y);
}

int32_t main() { fastio;
    time_t start = now();

    cin >> n >> h >> l >> r;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << res(0, 0) << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}