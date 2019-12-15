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
    int k; cin >> k;
    while (k--) {
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> freq(128);
        for (auto x : s) {
            freq[x]++;
        }
        for (auto x : t) {
            freq[x]++;
        }
        bool possible = true;
        for (auto f : freq) {
            if (f & 1) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << "Yes" << endl;
            vector<pair<int, int>> moves;

            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) {
                    auto x = find(t.begin() + i, t.end(), s[i]);
                    if (x != t.end()) {
                        int loc = x - t.begin();
                        t[loc] = s[i + 1];
                        s[i + 1] = s[i];
                        moves.push_back({ i + 2, loc + 1 });
                        s[i + 1] = t[i];
                        t[i] = s[i];
                        moves.push_back({ i + 2, i + 1 });
                    } else {
                        int loc = find(s.begin() + i + 1, s.end(), s[i]) - s.begin();
                        s[loc] = t[i];
                        t[i] = s[i];
                        moves.push_back({ loc + 1, i + 1 });
                    }
                }
            }

            cout << moves.size() << endl;
            for (auto m : moves) {
                cout << m.first << " " << m.second << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}