#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MOD (int) (1e9 + 7)

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fastio;
    int n, k;
    cin >> n >> k;
    getMat(points, n + 1, 3, 0);
    vector<int> line(201);
    vector<int> line_seg[201];
    for (int i = 1; i <= n; i++) {
        points[i][0] = i;
        cin >> points[i][1] >> points[i][2];
        for (int j = points[i][1]; j <= points[i][2]; j++) {
            line[j]++;
            line_seg[j].push_back(i);
        }
    }
    vector<bool> removed(n + 1);
    for (int i = 1; i <= 200; i++) {
        while (line[i] > k) {
            int max_len = 0, pos = 0;
            for (auto x : line_seg[i]) {
                if (!removed[x]) {
                    int len = points[x][2] + 1;
                    if (len > max_len) {
                        max_len = len;
                        pos = x;
                    }
                }
            }
            removed[pos] = true;
            for (int j = points[pos][1]; j <= points[pos][2]; j++) {
                line[j]--;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (removed[i]) count++;
    }
    cout << count << endl;
    for (int i = 1; i <= n; i++) {
        if (removed[i]) cout << i << " ";
    } cout << endl;
    return 0;
}