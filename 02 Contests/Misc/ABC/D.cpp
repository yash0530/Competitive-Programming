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
#define pout cout << fixed << setprecision(10);

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int productOfSubsetSums(vector<int> arr, int n) {
    if (accumulate(arr.begin(), arr.end(), 0) == 0) return 2;
    int ans = 1;
    for (int i = 0; i < n; i++) 
        ans = (ans % HELL * (arr[i] + 1) % HELL) % HELL; 
    return ans; 
}

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> arr;
    int res = 1;
    for (int i = 0; i < n; i++) {
        int p, y, x;
        cin >> p >> y >> x;
        int val = fastpow(p, x - y, HELL);
        arr.push_back(val == 1 ? 0 : val);
        res = (res % HELL * fastpow(p, y, HELL)) % HELL;
    }
    cout << (res * productOfSubsetSums(arr, n)) % HELL << endl;
    return 0;
}