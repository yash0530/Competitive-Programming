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

int32_t main() { fastio;
    time_t start = now();

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    vector<int> gaps(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i) {
            gaps[i - 1] = arr[i] - arr[i - 1];
        }
    }
    int res = arr.back() - arr[0];
    sort(gaps.rbegin(), gaps.rend());
    for (int i = 0; i < k - 1; i++) {
        res -= gaps[i];
    }
    cout << res + k << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}