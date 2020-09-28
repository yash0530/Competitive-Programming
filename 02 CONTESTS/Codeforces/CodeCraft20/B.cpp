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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string best = s;
        int best_val = 1;
        for (int i = 2; i < n + 1; i++) {
            string curr = s.substr(i - 1, n - i + 1);
            if ((n - i + 1) % 2) {
                string temp = s.substr(0, i - 1);
                reverse(temp.begin(), temp.end());
                curr += temp;
            } else {
                curr += s.substr(0, i - 1);
            }
            if (best.compare(curr) > 0) {
                best = curr;
                best_val = i;
            }
        }
        cout << best << endl;
        cout << best_val << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}