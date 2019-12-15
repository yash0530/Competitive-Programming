#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) { for (auto b : a) cout << b << " "; cout << "\n"; } cout << "\n";
#define getMat(x, n, m) vector<vector<int>> x(n, vector<int> (m))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cina(x, n) vector<int> x(n); for (int i = 0; i < n; i++) cin >> x[i];
#define sort(x) sort(x.begin(), x.end())
#define reverse(x) reverse(x.begin(), x.end())

#define MAX 5e4

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        int len = 0, cum_len = 0, i, prev_len = 0, x = 1;
        for (i = 1; i < MAX; i++) {
            if (i == 10 or i == 100 or i == 1000 or i == 10000) x++;
            len += x;
            cum_len += len;
            if (cum_len >= k) {
                break;
            }
            prev_len = cum_len;
        }
        string s = "";
        for (int j = 1; j <= i; j++) {
            s.append(to_string(j));
        }
        cout << s[k - prev_len - 1] << endl;
    }
    return 0;
}