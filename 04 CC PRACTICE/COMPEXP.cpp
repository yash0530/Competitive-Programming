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
#define pout cout << fixed << setprecision(10)

int32_t main() {
    fastio;
    int t, n, k; cin >> t;
    while (t--) {
        cin >> n >> k;
        pout << double(2 * (n - double((n - 1) / double(k)))) << endl;
    }
    return 0;
}