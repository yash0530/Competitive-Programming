#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n;
vector<int> tree;

void update(int index, int val) {
    while (index < n) {
        tree[index] += val;
        index += (index & -index);
    }
}

int read(int index) {
    int sum = 0;
    while (index) {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

struct events {
    int y, t, i;
    bool operator<(const events &a) {
        return make_pair(y, t) < make_pair(a.y, a.t);
    }
};

void solve() {
    int q;
    cin >> n >> q;
    vector<events> evs;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) {
            evs.push_back({ arr[i - 1], 1, i });
            evs.push_back({ arr[i], 3, i });
        } else {
            evs.push_back({ arr[i], 1, i });
            evs.push_back({ arr[i - 1], 3, i });
        }
    }
    vector<pair<int, int>> ranges(q);
    int a, b, c;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        ranges[i] = { --a, --b };
        evs.push_back({ c, 2, i });
    }
    sort(evs.begin(), evs.end());

    vector<int> res(q);
    tree.resize(n);
    for (auto e : evs) {
        if (e.t == 1) {
            update(e.i, 1);            
        } else if (e.t == 2) {
            res[e.i] = read(ranges[e.i].second) - read(ranges[e.i].first);
        } else {
            update(e.i, -1);
        }
    }
    for (auto r : res) {
        cout << r << endl;
    }
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}