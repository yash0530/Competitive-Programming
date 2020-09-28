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

int32_t main() { fastio;
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> planks(m);
    for (int i = 0; i < m; i++) {
        cin >> planks[i];
    }
    vector<int> potential;
    int count = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < d; j++) {
            potential.push_back(0);
        }
        for (int j = 0; j < planks[i]; j++) {
            potential.push_back(count);
        }
        count++;
    }
    for (int i = 1; i < d; i++) {
        potential.push_back(0);
    }
    int curr = (int) potential.size();
    if (curr < n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int remove = curr - n;
        vector<int> res;
        for (auto p : potential) {
            if (p == 0 and remove > 0) {
                remove--;
            } else {
                res.push_back(p);
            }
        }
        for (auto r : res) {
            cout << r << " ";
        } cout << endl;
    }
    return 0;
}