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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n < 1) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' and s[i + 1] == 'L') {
            cout << i + 1 << " " << i + 2 << endl;
            return;
        }
        if (s[i] == 'L' and s[i + 1] == 'R') {
            cout << i + 1 << " " << i + 2 << endl;
            return;
        }
        if (s[i] == 'U' and s[i + 1] == 'D') {
            cout << i + 1 << " " << i + 2 << endl;
            return;
        }
        if (s[i] == 'D' and s[i + 1] == 'U') {
            cout << i + 1 << " " << i + 2 << endl;
            return;
        }
    }
    map<pair<int, int>, int> H;
    int left = 0, up = 0, len = INF;
    H[{ left, up }] = -1;
    int low, high;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            left--;
        } else if (s[i] == 'R') {
            left++;
        } else if (s[i] == 'U') {
            up--;
        } else {
            up++;
        }
        if (H.find({ left, up }) == H.end()) {
        } else {
            int pev = H[{ left, up }];
            int curr_len = (i - pev);
            if (curr_len <= len) {
                len = curr_len;
                low = pev + 2;
                high = i + 1;
            }
        }
        H[{ left, up }] = i;
    }
    if (len == INF) {
        cout << -1 << endl;
    } else {
        cout << low << " " << high << endl;
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