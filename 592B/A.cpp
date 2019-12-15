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
#define srt(x) sort(x.begin(), x.end())
#define rev(x) reverse(x.begin(), x.end())

int32_t main() {
    fastio;

    int t; cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if (((int) ceil(a / double(c)) + (int) ceil(b / double(d))) <= k) {
            cout << (int) ceil(a / double(c)) << " " << (int) ceil(b / double(d)) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}