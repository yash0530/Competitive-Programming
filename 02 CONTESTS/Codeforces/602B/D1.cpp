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
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> arr(n);
    map<int, vector<int>> mp;
    vector<int> sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    for (auto &m : mp) {
        reverse(m.second.begin(), m.second.end());
    }
    sorted = arr;
    sort(sorted.begin(), sorted.end(), greater<int>());
    int m; cin >> m;
    while (m--) {
        map<int, vector<int>> mp2 = mp;
        int k, pos;
        cin >> k >> pos;
        vector<int> subset(k);
        for (int i = 0; i < k; i++) {
            subset[i] = mp2[sorted[i]].back();
            mp2[sorted[i]].pop_back();
        }
        sort(subset.begin(), subset.end());
        cout << arr[subset[pos - 1]] << endl;
    }
    return 0;
}