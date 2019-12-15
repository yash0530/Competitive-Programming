#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define int long long
#define uint unsigned long long
#define MOD (int) (1e9 + 7)
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    } return res;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        unordered_map<int, int> freq;
        int count = 0;
        for (int i = 0; i < d; i++) {
            freq[arr[i]]++;
            if (freq[arr[i]] == 1) {
                count++;
            }
        }
        int min_shows = count;
        int i = 0, j = d;
        while (j < n) {
            freq[arr[j]]++;
            if (freq[arr[j]] == 1) {
                count++;
            }
            freq[arr[i]]--;
            if (freq[arr[i]] == 0) {
                count--;
            }
            i++; j++;
            min_shows = min(min_shows, count);
        }
        cout << min_shows << endl;
    }
    return 0;
}