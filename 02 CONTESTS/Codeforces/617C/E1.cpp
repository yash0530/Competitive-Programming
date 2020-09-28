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

    int n; cin >> n;
    string s; cin >> s;

    vector<int> s1, s2;
    for (int i = 0; i < n; i++) {
        if (s1.empty()) {
            s1.push_back(i);
        } else if (s[s1.back()] <= s[i]) {
            s1.push_back(i);
        } else if (s2.empty()) {
            s2.push_back(i);
        } else if (s[s2.back()] <= s[i]) {
            s2.push_back(i);
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    vector<int> res(n);
    for (auto x : s2) {
        res[x] = 1;
    }
    for (auto r : res) {
        cout << r;
    } cout << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}