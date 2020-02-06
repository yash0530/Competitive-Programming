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

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % HELL;
    }
    return res;
}

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int len = 2 * n + 2;
        vector<int> arr(len);
        for (int i = 0; i < 2 * n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int sum = arr.front() + arr.back();
        int low = 0, high = len - 1;
        bool possible = true;
        map<pair<int, int>, int> freq;
        int count = 0, found = 0;
        while (low < high) {
            if (arr[low] + arr[high] == sum) {
                if ((found < 2) and (arr[low] == 0 or arr[high] == 0)) {
                    found++;
                } else {
                    freq[{ arr[low], arr[high] }]++;
                    if (arr[low] == arr[high]) {
                        count++;
                    }
                }
            } else {
                possible = false;
            }
            low++; high--;
        }
        if (!possible or found < 2) {
            cout << 0 << endl;
        } else {
            int num = fact(n - 1);
            num = (num * fastpow(2, max(0LL, n - 1 - count), HELL)) % HELL;
            int den = 1;
            for (auto f : freq) {
                den = (den * fact(f.second)) % HELL;
            }
            den = fastpow(den, HELL - 2, HELL);
            cout << (num * den) % HELL << endl;
        }
    }
    return 0;
}