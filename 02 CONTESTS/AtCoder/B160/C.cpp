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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    
    int k, n;
    cin >> k >> n;
    int arr[2 * n];
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	arr[i + n] = arr[i];
    }
    int pref[2 * n];
    pref[0] = 0;
    for (int i = 1; i < 2 * n; i++) {
    	int diff = arr[i] - arr[i - 1];
    	if (diff < 0) {
    		diff += k;
    	}
    	pref[i] = pref[i - 1] + diff;
    }
    int ans = INF;
    for (int i = n - 1; i < 2 * n; i++) {
    	ans = min(ans, pref[i] - pref[i - n + 1]);
    }
    cout << ans << endl;

    return 0;
}