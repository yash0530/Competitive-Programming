#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m) vector<vector<int>> x(n, vector<int> (m))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool possible(vector<int> &prefix, int pos, int mid, int k) {
    int reqd = k * mid;
    int have = prefix[pos] - prefix[pos - mid];
    if ((pos - mid + 1) >= (reqd - have)) {
        return true;
    }
    return false;
}

void addMore(vector<int> &prefix, int low, int high, int pos, int k, int &ans) {
    if (low > high) {
        return;
    }
    int mid = (high + low) / 2;
    if (possible(prefix, pos, mid, k)) {
        ans = max(ans, mid);
        return addMore(prefix, mid + 1, high, pos, k, ans);
    } else {
        return addMore(prefix, low, mid - 1, pos, k, ans);
    }
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        while (q--) {
            int k; cin >> k;
            auto lb = lower_bound(arr.begin(), arr.end(), k);
            int res = arr.end() - lb;
            if (res != n) {
                int ans = 0;
                addMore(prefix, 0, lb - arr.begin() - 1, lb - arr.begin() - 1, k, ans);
                res += ans;
            }
            cout << res << endl;
        }
    }
    return 0;
}