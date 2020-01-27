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
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<int> freq(128);
    for (int i = 0; i < k; i++) {
        char x; cin >> x;
        freq[x] = true;
    }
    vector<int> S;
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (!freq[s[i]]) {
            S.push_back(i - start);
            start = i + 1;
        }
    }
    S.push_back(n - start);
    int res = 0;
    for (auto r : S) {
        res += (r + 1) * r / 2;
    }
    cout << res << endl;
    return 0;
}