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

int distance(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        pair<int, int> start;
        cin >> start.first >> start.second;
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> N(n);
        vector<pair<int, int>> M(m);
        vector<pair<int, int>> K(k);
        for (int i = 0; i < n; i++) {
            cin >> N[i].first >> N[i].second;
        }
        for (int i = 0; i < m; i++) {
            cin >> M[i].first >> M[i].second;
        }
        for (int i = 0; i < k; i++) {
            cin >> K[i].first >> K[i].second;
        }

        vector<int> dists_m(m);
        for (int i = 0; i < m; i++) {
            pair<int, int> curr;
            int dist = INF;
            for (int j = 0; j < k; j++) {
                int d = distance(M[i], K[j]);
                if (d < dist) {
                    dist = d;
                }
            }
            dists_m[i] = dist;
        }

        vector<int> dists_n(n);
        for (int i = 0; i < n; i++) {
            pair<int, int> curr;
            int dist = INF;
            for (int j = 0; j < k; j++) {
                int d = distance(N[i], K[j]);
                if (d < dist) {
                    dist = d;
                }
            }
            dists_n[i] = dist;
        }

        double result = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result = min(result, (double) (sqrt(distance(start, N[i])) + sqrt(distance(N[i], M[j])) + sqrt(dists_m[j])));
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = min(result, (double) (sqrt(distance(start, M[i])) + sqrt(distance(M[i], N[j])) + sqrt(dists_n[j])));
            }
        }
        pout << result << endl;
    }
    return 0;
}