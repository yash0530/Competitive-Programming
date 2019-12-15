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

int f(int a) {
    int count = 0;
    while (a % 2 == 0) {
        a >>= 1;
        count++;
    }
    return count;
}

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> bits(65);
    int best = 0, best_dist = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int x = f(arr[i]);
        bits[x]++;
        if (best < bits[x]) {
            best = bits[x];
            best_dist = x;
        }
    }
    cout << n - best << endl;
    for (int i = 0; i < n; i++) {
        if (best_dist != f(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}