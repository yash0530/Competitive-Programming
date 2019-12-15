#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MOD (int) (1e9 + 7)

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

#define MAX (int) (2e5 + 5)

int32_t main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> prefix(MAX);
    vector<vector<int>> prefix_segs(MAX);
    vector<pair<int, int>> segs(n + 1);
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        segs[i] = { a, b };
        prefix[a]++;
        prefix[b + 1]--;
        prefix_segs[a].push_back(i);
        prefix_segs[b + 1].push_back(-i);
    }
    for (int i = 1; i < MAX; i++) {
        prefix[i] = prefix[i] + prefix[i - 1];
    }

    set<pair<int, int>> curr_segs;
    vector<int> prefix_removed(MAX);
    int currRemoved = 0;
    vector<bool> res(MAX);
    for (int i = 0; i < MAX; i++) {
        currRemoved += prefix_removed[i];
        for (auto seg : prefix_segs[i]) {
            if (seg > 0) {
                curr_segs.insert({ segs[seg].second, seg });
            } else {
                curr_segs.erase({ segs[-seg].second, -seg });
                prefix_removed[segs[-seg].second + 1]--;
            }
        }
        while ((prefix[i] - currRemoved) > k) {
            auto p = *curr_segs.rbegin();
            curr_segs.erase(p);
            res[p.second] = true;
            prefix_removed[p.first + 1]--;
            currRemoved++;
        }
    }
    cout << accumulate(res.begin(), res.end(), 0) << endl;
    for (int i = 0; i < MAX; i++) {
        if (res[i]) {
            cout << i << " ";
        }
    } cout << endl;
    return 0;
}