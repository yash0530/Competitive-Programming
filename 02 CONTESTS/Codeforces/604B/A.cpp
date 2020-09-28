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
        string s; cin >> s;
        int n = s.length();
        bool possible = true; 
        for (int i = 0; i < n - 1; i++) {
            if (i != n - 1) {
                if (s[i] == s[i + 1] and (s[i] != '?')) {
                    possible = false;
                    break;
                }
            }
            if (s[i] == '?') {
                if (i == 0) {
                    if (s[i + 1] == '?') {
                        s[i] = 'a';
                    } else {
                        s[i] = (s[i + 1] - 'a' + 1) % 3 + 'a';
                    }
                } else {
                    if (s[i - 1] == s[i + 1]) {
                        s[i] = (s[i - 1] - 'a' + 1) % 3 + 'a';
                    } else if (s[i - 1] + s[i + 1] == 'b' + 'a') {
                        s[i] = 'c';
                    } else if (s[i - 1] + s[i + 1] == 'c' + 'a') {
                        s[i] = 'b';
                    } else if (s[i - 1] + s[i + 1] == 'c' + 'b') {
                        s[i] = 'a';
                    } else {
                        s[i] = (s[i - 1] - 'a' + 1) % 3 + 'a';
                    }
                }
            }
        }
        if (s[n - 1] == '?') {
            if (n == 1) {
                s[0] = 'a';
            } else {
                s[n - 1] = (s[n - 2] - 'a' + 1) % 3 + 'a';
            }
        }
        if (!possible) {
            cout << -1 << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}