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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> S;
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] >= arr[i]) {
            S.push_back(i - start);
            start = i;
        }
    }
    S.push_back(n - start);
    int res = S.back();
    int index = 0;
    for (int i = 0; i < (int) S.size() - 1; i++) {
        res = max(S[i], res);
        if (S[i] != 1 and S[i + 1] != 1) {
            if (arr[index + S[i] - 2] < arr[index + S[i]]) {
                res = max(res, S[i] + S[i + 1] - 1);
            }
            if (arr[index + S[i] - 1] < arr[index + S[i] + 1]) {
                res = max(res, S[i] + S[i + 1] - 1);
            }
        }
        index += S[i];
    }
    cout << res << endl;
    return 0;
}