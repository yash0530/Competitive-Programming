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

int32_t main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> prefix(n);
    vector<int> p_reqd(n);
    prefix[0] = arr[0];
    p_reqd[0] = 0;
    for (int i = 1; i < n; i++) {
        prefix[i] = arr[i] + prefix[i - 1];
        p_reqd[i] = arr[i] * (i + 1) - prefix[i];
    }
    vector<int> suffix(n);
    vector<int> s_reqd(n);
    suffix[n - 1] = arr[n - 1];
    s_reqd[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = arr[i] + suffix[i + 1];
        s_reqd[i] = suffix[i] - arr[i] * (n - i); 
    }
    reverse(s_reqd.begin(), s_reqd.end());
    int diff = 1e18;
    for (int i = n - 1; i >= 0; i--) {
        int curr = 1e18, left;
        if (i == n - 1) {
            left = k;
        } else {
            left = k - (suffix[i + 1] - (n - i - 1) * arr[i]);
        }
        if (left >= 0) {
            int loc = upper_bound(p_reqd.begin(), p_reqd.end(), left) - p_reqd.begin() - 1;
            if (loc <= i) {
                curr = max(arr[i] - (arr[loc] + ((left - p_reqd[loc]) / (loc + 1))), (int) 0);
            }
        }
        diff = min(diff, curr);
    }
    for (int i = 0; i < n; i++) {
        int curr = 1e18, left;
        if (i == 0) {
            left = k;
        } else {
            left = k - (i * arr[i] - prefix[i - 1]);
        }
        if (left >= 0) {
            int loc = upper_bound(s_reqd.begin(), s_reqd.end(), left) - s_reqd.begin() - 1;
            curr = max(arr[n - loc - 1] - arr[i] - ((left - s_reqd[loc]) / (loc + 1)), (int) 0);
        }
        diff = min(diff, curr);
    }
    cout << diff << endl;
    return 0;
}