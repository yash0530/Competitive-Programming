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
    int n, x;
    cin >> n >> x;
    string s; cin >> s;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1] + (s[i - 1] == '0' ? 1 : -1);
    }
    if (arr.back() == 0) {
        for (int i = 1; i <= n; i++) {
            if (arr[i] == x) {
                cout << -1 << endl;
                return;
            }
        }
        if (x == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    if (x >= 0 and arr.back() > 0) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (x >= arr[i]) {
                if ((x - arr[i]) % arr.back() == 0) {
                    count++;
                }    
            }
        }
        if (x == 0) count++;
        cout << count << endl;
        return;
    }
    if (x < 0) {
        if (arr.back() > 0) {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (arr[i] <= x) {
                    if ((x - arr[i]) % arr.back() == 0) {
                        count++;
                    }
                }
            }
            cout << count << endl;
        } else {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (x <= arr[i]) {
                    if ((arr[i] - x) % -arr.back() == 0) {
                        count++;
                    }
                }
            }
            cout << count << endl;
        }
    } else if (x >= 0 and arr.back() < 0) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (x <= arr[i]) {
                if ((arr[i] - x) % -arr.back() == 0) {
                    count++;
                }
            }
        }
        if (x == 0) count++;
        cout << count << endl;
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