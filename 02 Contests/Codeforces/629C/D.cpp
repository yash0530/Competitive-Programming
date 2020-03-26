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

int n;
const int maxN = 2e5 + 5;
int arr[maxN];
int res[maxN];

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        arr[n] = arr[0];
        res[0] = 1; int prev = 1, mx = 1;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] == arr[i - 1]) {
                res[i] = prev;
            } else {
                if (prev == 1) {
                    mx = 2;
                    res[i] = 2;
                    prev = 2;
                } else {
                    res[i] = 1;
                    prev = 1;
                }
            }
        }
        if (prev == 1) {
            if (arr[n - 2] == arr[0] and arr[n - 2] == arr[n - 1]) {
                res[n - 1] = 1;
                cout << mx << endl;
            } else {
                res[n - 1] = 2;
                cout << 2 << endl;
            }
        } else {
            if (arr[n - 2] == arr[n - 1]) {
                res[n - 1] = 2;
                cout << 2 << endl;
            } else if (arr[n - 1] == arr[0]) {
                res[n - 1] = 1;
                cout << 2 << endl;
            } else {
                res[n - 1] = 3;
                bool found = false; int index = -1;
                for (int i = 0; i < n - 1; i++) {
                    if (res[i] == res[i + 1]) {
                        found = true;
                        index = i + 1;
                        break;
                    }
                }
                if (found) {
                    for (int i = index; i < n - 1; i++) {
                        if (res[i] == 1) res[i] = 2;
                        else res[i] = 1;
                    }
                    res[n - 1] = 2;
                    cout << 2 << endl;
                } else {
                    cout << 3 << endl;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        } cout << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}