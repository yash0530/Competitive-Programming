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

int sum, n;
vector<pair<int, int>> arr;
map<pair<int, int>, pair<int, int>> H;

pair<int, int> res(int curr, int index) {
    if (H.find({ curr, index }) != H.end()) {
        return H[{ curr, index }];
    }
    if (index == n - 1) {
        int d1 = abs(sum - (sum - curr - arr[index].first) * 2);
        int d2 = abs(sum - (sum - curr - arr[index].first) * 2);
        if (d1 < d2) {
            H[{ curr, index }] = { d1, 0 };
            return { d1, 0 };
        } else {
            H[{ curr, index }] = { d2, 0 };
            return { d2, 0 };
        }
    }
    H[{ curr, index }] = min(make_pair(res(curr + arr[index].first, index + 1).first, 0),
                            make_pair(res(curr + arr[index].second, index + 1).first, 1));
    return H[{ curr, index }];
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        H.clear();
        cin >> n;
        vector<string> mat(n);
        arr.assign(n, { 0, 0 });
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> mat[i];
            for (int j = 0; j < n / 2; j++) {
                arr[i].first += mat[i][j] - '0';
            }
            for (int j = n / 2; j < n; j++) {
                arr[i].second += mat[i][j] - '0';
            }
            sum += arr[i].first + arr[i].second;
        }
        res(0, 0);
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (H[{ curr, i }].second) {
                reverse(mat[i].begin(), mat[i].end());
            }
            cout << mat[i] << endl;
            if (H[{ curr, i }].second) {
                curr += arr[i].second;
            } else {
                curr += arr[i].first;
            }
        }
    }
    return 0;
}