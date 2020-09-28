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

vector<int> prefix(401);

int DOW(int m, int y) {  
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    int x = ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + 1) % 7;
    if (x == 0) return 7;
    return x;  
}

int LEAP(int x) {
    if (x % 400 == 0) return true;
    if (x % 100 == 0) return false;
    if (x % 4 == 0) return true;
    return false;
}

int32_t main() { fastio
    for (int i = 1; i <= 400; i++) {
        prefix[i] = prefix[i - 1];
        if (DOW(2, i) == 6 or (DOW(2, i) == 7 and !LEAP(i))) {
            prefix[i]++;
        }
    }
    deba(prefix);
    int t; cin >> t;
    while (t--) {
        int m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;
        if (m1 > 2) y1++;
        if (m2 < 2) y2--;
        if (y1 <= y2) {
            if (y1 / 400 == y2 / 400) {
                y1 = y1 % 400;
                y2 = y2 % 400;
                cout << prefix[y2] - prefix[y1 ? (y1 - 1) : y1] << endl;
            } else {
                int factor = y2 / 400 - y1 / 400;
                y1 = y1 % 400;
                y2 = y2 % 400;
                int res = prefix[400] - prefix[y1 ? (y1 - 1) : y1];
                factor--;
                res += factor * 101;
                res += prefix[y2];
                cout << res << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}