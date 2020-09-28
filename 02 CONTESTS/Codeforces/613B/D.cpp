#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

int res(int index, vector<int> arr) {
    if (index >= 0) {
        vector<int> zero, one;
        for (auto a : arr) {
            if ((1 << index) & a) {
                one.push_back(a);
            } else {
                zero.push_back(a);
            }
        }
        if (one.size() and zero.size()) {
            return (1 << index) + min(res(index - 1, one), res(index - 1, zero));
        }
        return res(index - 1, arr);
    }
    return 0;
}

int32_t main() { fastio;
    
	int n; cin >> n;
	vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << res(30, arr) << endl;

    return 0;
}