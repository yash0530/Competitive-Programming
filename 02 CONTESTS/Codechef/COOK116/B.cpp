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

void move(int &x, int &y, char dir) {
    if (dir == 'L') {
        x--;
    } else if (dir == 'R') {
        x++;
    } else if (dir == 'U') {
        y++;
    } else {
        y--;
    }
}

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    move(x, y, s[0]);
    char prev = s[0];
    for (int i = 1; i < n; i++) {
        if (prev == 'L' or prev == 'R') {
            if (s[i] == 'U' or s[i] == 'D') {
                move(x, y, s[i]);
            }
        }
        if (prev == 'U' or prev == 'D') {
            if (s[i] == 'L' or s[i] == 'R') {
                move(x, y, s[i]);
            }
        }
        prev = s[i];
    }
    cout << x << " " << y << endl;
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