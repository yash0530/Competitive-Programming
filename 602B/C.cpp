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

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        string t;
        for (int i = 0; i < k - 1; i++) {
            t.push_back('(');
            t.push_back(')');
        }
        for (int i = 0; i < (n - 2 * k + 2) / 2; i++) {
            t.push_back('(');
        }
        for (int i = 0; i < (n - 2 * k + 2) / 2; i++) {
            t.push_back(')');
        }
        vector<pair<int, int>> moves;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == t[i]) {
                        moves.push_back({ i + 1, j + 1 });
                        reverse(s.begin() + i, s.begin() + j + 1);
                        break;
                    }
                }
            }
        }
        cout << moves.size() << endl;
        for (auto m : moves) {
            cout << m.first << " " << m.second << endl;
        }
    }
}