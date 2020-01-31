#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << endl
// using namespace boost::multiprecision;
using namespace std;

int32_t main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (x - y == 1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}