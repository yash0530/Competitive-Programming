#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

bool possible(int soilder, vector<vector<int>> traps, int n, int t) {
    vector<pair<int, int>> segs;
    for (auto tr : traps) {
        if (tr[2] > soilder) {
            if (tr[0] <= tr[1]) {
                segs.push_back({ tr[0], tr[1] });
            }
        }
    }
    int time = (n + 1);
    if (segs.size()) {
        vector<pair<int, int>> res_segs;
        res_segs.push_back(segs[0]);
        int j = 0;
        for (int i = 1; i < (int) segs.size(); i++) {
            if (segs[i].first <= res_segs[j].second) {
                res_segs[j].first = min(segs[i].first, res_segs[j].first);
                res_segs[j].second = max(segs[i].second, res_segs[j].second);
            } else {
                res_segs.push_back(segs[i]);
                j++;
            }
        }
        for (auto s : res_segs) {
            time += (s.second - s.first + 1) * 2;
        }
    }
    return time <= t;
}

void BS(vector<int> &soilders, vector<vector<int>> traps, int n, int t, int low, int high, int &ans) {
    if (low > high) return;
    int mid = (low + high) / 2;
    if (possible(soilders[mid - 1], traps, n, t)) {
        ans = mid;
        BS(soilders, traps, n, t, mid + 1, high, ans);
    } else {
        BS(soilders, traps, n, t, low, mid - 1, ans);
    }
}

int32_t main() { fastio;
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vector<int> soilders(m);
    for (int i = 0; i < m; i++) {
        cin >> soilders[i];
    }
    getMat(traps, k, 3, 0);
    for (int i = 0; i < k; i++) {
        cin >> traps[i][0] >> traps[i][1] >> traps[i][2];
    }
    sort(soilders.begin(), soilders.end(), greater<int>());
    sort(traps.begin(), traps.end());
    int ans = 0;
    BS(soilders, traps, n, t, 1, m, ans);
    cout << ans << endl;
    return 0;
}