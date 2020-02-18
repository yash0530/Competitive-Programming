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
    int t; cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        int loc = 0, times = 0;
        bool possible = false;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (p % arr[i]) {
                loc = i;
                times = (p + arr[i]) / arr[i];
                possible = true;
            }
        }
        if (possible) {
            cout << "YES ";
            for (int i = 0; i < n; i++) {
                if (loc == i) {
                    cout << times << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        } else {
            if (n == 1) cout << "NO" << endl;
            else {
                int left = -1, right = -1;
                int left_;
                for (int i = 0; i < n - 1; i++) {
                    if (arr[i] > 1) {
                        for (int j = i + 1; j < n; j++) {
                            if (arr[j] != p) {
                                if (arr[j] % arr[i]) {
                                    left = i; right = j;
                                    left_ = (p - arr[j] + arr[i]) / arr[i];
                                    break;
                                }
                            }
                        }
                    }
                }
                if (left != -1) {
                    cout << "YES ";
                    for (int i = 0; i < n; i++) {
                        if (i == left) {
                            cout << left_ << " ";
                        } else if (i == right) {
                            cout << 1 << " ";
                        } else {
                            cout << 0 << " ";
                        }
                    } cout << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }

    }
    return 0;
}