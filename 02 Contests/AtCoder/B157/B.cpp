#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
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

    getMat(arr, 3, 3, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    getMat(marked, 3, 3, 0);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (x == arr[i][j]) {
                    marked[i][j] = 1;
                }
            }
        }
    }

    int poss = false;
    for (int i = 0; i < 3; i++) {
        int p = true;
        for (int j = 0; j < 3; j++) {
            if (!marked[i][j]) {
                p = false;
            }
        }
        if (p) {
            poss = true;
            break;
        }
    }

    for (int j = 0; j < 3; j++) {
        int p = true;
        for (int i = 0; i < 3; i++) {
            if (!marked[i][j]) {
                p = false;
            }
        }
        if (p) {
            poss = true;
            break;
        }
    }

    if (marked[1][1] == marked[2][2] and marked[2][2] == marked[0][0] and marked[1][1] == 1) {
        poss = true;
    }

    if (marked[0][2] == marked[1][1] and marked[2][0] == marked[1][1] and marked[1][1] == 1) {
        poss = true;
    }

    if (poss) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}