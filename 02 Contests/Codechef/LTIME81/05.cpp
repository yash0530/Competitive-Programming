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

int play(multiset<int> &a1, multiset<int> &d1, multiset<int> &a2, multiset<int> &d2, int s1, int s2) {
    if (a1.empty() or d2.empty()) {
        return s1 - s2;
    }
    int val = s1 - s2;
    auto mn = a1.begin();
    auto mx = --d2.end();
    s2 -= *mx;
    d1.insert(*mn);
    a1.erase(mn);
    d2.erase(mx);
    return max(val, -play(a2, d2, a1, d1, s2, s1));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    string s1, s2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        sum1 += v1[i];
    } cin >> s1;
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
        sum2 += v2[i];
    } cin >> s2;

    multiset<int> attack1, attack2, defense1, defense2;
    for (int i = 0; i < n; i++) {
        if (s1[i] == 'A') {
            attack1.insert(v1[i]);
        } else {
            defense1.insert(v1[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (s2[i] == 'A') {
            attack2.insert(v2[i]);
        } else {
            defense2.insert(v2[i]);
        }
    }

    cout <<  play(attack1, defense1, attack2, defense2, sum1, sum2) << endl;
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