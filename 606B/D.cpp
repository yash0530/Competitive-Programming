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
        int n; cin >> n;
        vector<string> s(n);
        set<string> s10;
        set<string> s01;
        int n00 = 0, n11 = 0, n01 = 0, n10 = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (s[i].front() == s[i].back()) {
                n00 += s[i].front() == '0';
                n11 += s[i].front() == '1';
            } else if (s[i].front() == '0' and s[i].back() == '1') {
                s01.insert(s[i]);
                n01++;
            } else {
                s10.insert(s[i]);
                n10++;
            }
        }
        if (n00 and n11 and !n01 and !n10) {
            cout << -1 << endl;
        } else {
            vector<int> res;
            if (n01 > n10 + 1) {
                for (int i = 0; i < n; i++) {
                    if (n01 <= n10 + 1) break;
                    if (s[i].front() == '0' and s[i].back() == '1') {
                        string ss(s[i]);
                        reverse(ss.begin(), ss.end());
                        if (s10.find(ss) == s10.end()) {
                            n10++;
                            n01--;
                            res.push_back(i + 1);
                        }
                    }
                }
            } else if (n10 > n01 + 1) {
                for (int i = 0; i < n; i++) {
                    if (n10 <= n01 + 1) break;
                    if (s[i].front() == '1' and s[i].back() == '0') {
                        string ss(s[i]);
                        reverse(ss.begin(), ss.end());
                        if (s01.find(ss) == s01.end()) {
                            n01++;
                            n10--;
                            res.push_back(i + 1);
                        }
                    }
                }
            }
            cout << res.size() << endl;
            for (auto r : res) {
                cout << r << " ";
            } cout << endl;
        }
    }
    return 0;
}