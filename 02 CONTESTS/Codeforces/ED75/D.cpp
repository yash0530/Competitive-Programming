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

int fastpow(int a, int b, int m) {
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

bool possible(vector<pair<int, int>> arr, int median, int sal) {
    int n = arr.size();
    int rem = (n + 1) >> 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].first >= median) {
            rem--;
        }
        sum += arr[i].first;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i].first < median and arr[i].second >= median and rem > 0) {
            sum -= arr[i].first;
            sum += median;
            rem--;
        }
    }
    if (rem > 0 or sum > sal) {
        return false;
    }
    return true;
}

void BS(vector<pair<int, int>> arr, int low, int high, int &res, int sal) {
    if (low <= high) {
        int mid = (low + high) >> 1;
        if (possible(arr, mid, sal)) {
            res = max(res, mid);
            BS(arr, mid + 1, high, res, sal);
        } else {
            BS(arr, low, mid - 1, res, sal);
        }
    }
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end());
        int res = 0;
        BS(arr, 0, 1e9, res, s);
        cout << res << endl;
    }
    return 0;
}