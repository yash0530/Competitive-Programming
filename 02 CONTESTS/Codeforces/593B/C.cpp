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

int32_t main() {
    fastio;
    int n; cin >> n;
    vector<int> first(n), last(n);
    for (int i = 0; i < n; i++) {
        first[i] = i * n + 1;
    }
    for (int i = 0; i < n; i++) {
        last[i] = (i + 1) * n;
    }
    bool outer = true;
    for (int i = 0; i < n; i++) {
        bool inner = outer;
        for (int i = 0; i < n; i++) {
            if (inner) {
                cout << first[i]++ << " ";
            } else {
                cout << last[i]-- << " ";
            }
            inner = !inner;
        } cout << endl;
        outer = !outer;
    }
    return 0;
}