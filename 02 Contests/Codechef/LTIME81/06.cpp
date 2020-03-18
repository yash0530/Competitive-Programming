#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

struct event {
    int x, type, y;
    bool operator<(const event &a) {
        return make_pair(x, type) < make_pair(a.x, a.type);
    }
};

int main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> xl(n), xr(n);
        for (int i = 0; i < n; i++) {
            cin >> xl[i] >> xr[i];
        }
        map<int, int> mpl, mpr;
        for (int i = 0; i < n; i++) {
            if (mpl.find(xl[i]) == mpl.end()) {
                mpl[xl[i]] = xr[i];
            } else {
                mpl[xl[i]] = max(xr[i], mpl[xl[i]]);
            }
            if (mpr.find(xr[i]) == mpr.end()) {
                mpr[xr[i]] = xl[i];
            } else {
                mpr[xr[i]] = min(xl[i], mpr[xr[i]]);
            }
        }

        // creating events
        vector<event> ve;
        for (auto m : mpr) {
            // right segment should be active from the range [xl, xr)
            // => [m.second, m.first)   
            // add segment event
            ve.push_back({ m.second, 1, m.first });
            // remove segment event
            ve.push_back({ m.first, 2, m.first });
        }
        for (auto m : mpl) {
            ve.push_back({ m.first, 3, m.second });
        }
        sort(ve.begin(), ve.end());

        // sweep
        long long res = 1;
        ordered_set s;
        for (auto e : ve) {
            if (e.type == 1) {
                s.insert(e.y);
            } else if (e.type == 2) {
                s.erase(e.y);
            } else {
                res += s.order_of_key(e.y + 1);
            }
        }
        cout << res << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}