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

struct R {
    int a, b, c;
};

int32_t main() { fastio;
    time_t start = now();

    int n, m; cin >> n >> m;
    vector<int> bal(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bal[a] += c;
        bal[b] -= c;
    }
    vector<int> pos, neg;
    vector<R> res;
    for (int i = 1; i <= n; i++) {
        if (bal[i] < 0) neg.push_back(i);
        else if (bal[i] > 0) pos.push_back(i);
    }
    while (!neg.empty()) {
        int trans = min(abs(bal[neg.back()]), bal[pos.back()]);
        bal[neg.back()] += trans;
        bal[pos.back()] -= trans;
        res.push_back({ pos.back(), neg.back(), trans });
        if (bal[pos.back()] == 0 and bal[neg.back()] == 0) {
            pos.pop_back();
            neg.pop_back();
        } else if (bal[neg.back()] == 0) {
            neg.pop_back();
        } else {
            pos.pop_back();
        }
    }
    cout << res.size() << endl;
    for (auto r : res) {
        cout << r.a << " " << r.b << " " << r.c << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}