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

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        vector<int> M(64);
        int sum = 0;
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
            sum += arr[i];
            M[log2(arr[i])]++;
        }
        if (sum < n) {
            cout << -1 << endl;
            continue;
        }
        int i = 0, res = 0;
        while (i < 63) {
            if ((1LL << i) & n) {
                if (M[i] > 0) {
                    M[i]--;
                } else {
                    while (M[i] == 0) {
                        i++;
                        res++;
                    }
                    M[i]--;
                    continue;
                }
            }
            M[i + 1] += M[i] / 2;
            i++;
        }
        cout << res << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}