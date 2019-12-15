#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define MOD (int) (1e9 + 7)
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

bool possible(vector<int> tickets, int a, int x, int b, int y, int c, int z, int k) {
    int sum = 0;
    for (int i = 0; i < c; i++) {
        sum += (tickets[i] * z) / 100;
        if (sum >= k) {
            return true;
        }
    }
    for (int i = c; i < (c + a); i++) {
        sum += (tickets[i] * x) / 100;
        if (sum >= k) {
            return true;
        }
    }
    for (int i = (c + a); i < (c + a + b); i++) {
        sum += (tickets[i] * y) / 100;
        if (sum >= k) {
            return true;
        }
    }
    return false;
}

void BS(vector<int> tickets, int &res, int x, int a, int y, int b, int k, int low, int high) {
    if (low <= high) {
        int n = (low + high) >> 1;
        int lcm = ((a * b) / __gcd(a, b));
        int c_count = n / lcm, a_count = n / a, b_count = n / b;
        a_count -= c_count;
        b_count -= c_count;
        int xt = x, yt = y, a_countt = a_count, b_countt = b_count;
        if (x < y) {
            swap(a_countt, b_countt);
            swap(xt, yt);
        }
        if (possible(tickets, a_countt, xt, b_countt, yt, c_count, x + y, k)) {
            res = min(res, n);
            BS(tickets, res, x, a, y, b, k, low, n - 1);
        } else {
            BS(tickets, res, x, a, y, b, k, n + 1, high);
        }
    }
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> tickets(n);
        for (int i = 0; i < n; i++) {
            cin >> tickets[i];
        }
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        int k; cin >> k;
        sort(tickets.begin(), tickets.end(), greater<int>());
        if (k == 0) cout << 0 << endl;
        else {
            int res = INF;
            BS(tickets, res, x, a, y, b, k, 1, tickets.size());
            if (res == INF) cout << -1 << endl;
            else cout << res << endl;
        }
    }
    return 0;
}