// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
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
    int n; cin >> n;
    cina(arr, n);
    int high = *max_element(arr.begin(), arr.end());
    vector<int> stolen;
    for (auto a : arr) {
        if (high != a) {
            stolen.push_back(high - a);
        }
    }
    if (stolen.size() > 1) {
        int gcd = __gcd(stolen[0], stolen[1]);
        for (int i = 2; i < stolen.size(); i++) {
            gcd = __gcd(gcd, stolen[i]);
        }
        int count = 0;
        for (int i = 0; i < stolen.size(); i++) {
            count += stolen[i] / gcd;
        }
        cout << count << " " << gcd << endl;
    } else if (stolen.size() == 1) {
        cout << 1 << " " << stolen[0] << endl;
    } else {
        cout << 0 << " " << 0 << endl;
    }
    return 0;
}