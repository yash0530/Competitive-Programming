#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> arr(n), og(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
        og[i] = arr[i];
    }
    for (auto &m : mp) {
        reverse(m.second.begin(), m.second.end());
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int m; cin >> m;
    vector<pair<pair<int, int>, int>> queries(m);
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());
    ordered_set s;
    for (int i = 0; i < m; i++) {
        while ((int) s.size() < queries[i].first.first) {
            s.insert(mp[arr[s.size()]].back());
            mp[arr[s.size() - 1]].pop_back();
        }
        res[queries[i].second] = og[*(s.find_by_order(queries[i].first.second - 1))];
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << endl;
    }
    return 0;
}