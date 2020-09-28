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

void solve() {
    int n; cin >> n;
    vector<int> arr(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    int mx = *max_element(arr.begin(), arr.end());
    vector<int> pos;
    for (int i = 0; i < 2 * n; i++) {
        if (arr[i] == mx) {
            pos.push_back(i);
        }
    }
    if (pos.size() == 1) {
        cout << n / 2 << endl;
    } else {
        int len = -1;
        for (int i = 1; i < pos.size(); i++) {
            len = max(len, pos[i] - pos[i - 1]);
        }
        if (len >= n / 2) {
            cout << len - n / 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}