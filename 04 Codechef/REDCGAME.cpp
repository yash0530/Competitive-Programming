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

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int i, sum = 0;
        for (i = 0; i < n; i++) {
            if (arr[i] > k) {
                break;
            }
            sum += arr[i];
        }
        if (n - i == 0) {
            cout << sum << endl;
        } else if (n - i == 1) {
            cout << sum + arr[n - 1] << endl;
        } else if (n - i == 2) {
            cout << sum + 2 * k + arr[n - 1] - arr[n - 2] << endl;
        } else {
            vector<int> prefix(n + 1);
            for (int j = i; j < n - 1; j++) {
                sum += k;
                prefix[j + 1] = prefix[j] + (arr[j] - k);
            }
            int max_elem = prefix[n];
            int diff = 1e18;
            for (int j = n - 1; j >= i; j--) {
                diff = min(diff, abs(max_elem - prefix[i]) * 2 - max_elem);
            }
            if (diff == 1e18) {
                diff = 0;
            }
            cout << sum + arr[n - 1] - diff << endl;
        }
    }
    return 0;
}