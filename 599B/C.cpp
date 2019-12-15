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

vector<int> getFactors(int n) {
    vector<int> factors = { 1 };
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

int lcm(int a, int b) {
    return (int) (((double) a / __gcd(a, b)) * b);
}

int lcmArray(vector<int> arr) {
    if (arr.size() < 2) {
        return arr[0];
    }
    int ans = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> factors = getFactors(n);
    int l = lcmArray(factors);
    cout << n / l << endl;
    return 0;
}