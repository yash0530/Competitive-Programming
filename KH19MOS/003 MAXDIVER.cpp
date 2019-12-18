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

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<int> same;
        int prev = arr[0], count = 1;
        for (int i = 1; i < n; i++) {
            if (prev == arr[i]) {
                if (count == 1) {
                    same.push_back(1);
                } else {
                    same[same.size() - 1]++;
                }
                count++;
            } else {
                prev = arr[i];
                count = 1;
            }
        }
        priority_queue<int> pq(same.begin(), same.end());
        while (!pq.empty() and k > 0) {
            int x = pq.top(); pq.pop();
            x--; k--;
            if (x) pq.push(x);
        }
        int sum = 0;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            sum += (x * (x + 1) / 2);
        }
        cout << (n * (n - 1) / 2) - sum << endl;
    }
    return 0;
}