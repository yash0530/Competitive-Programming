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
        vector<bool> marked(s.length());
        vector<int> res;
        string x = "twone";
        if (s.length() >= 3) {
            if (s.length() >= 5) {
                for (int i = 0; i < s.length() - 4; i++) {
                    if (x.compare(s.substr(i, 5)) == 0) {
                        marked[i] = true;
                        marked[i+1] = true;
                        marked[i+2] = true;
                        marked[i+3] = true;
                        marked[i+4] = true;
                        res.push_back(i+3);
                    }
                }
            }
            x = "one";
            for (int i = 0; i < s.length() - 2; i++) {
                if (!marked[i] and x.compare(s.substr(i, 3)) == 0) {
                    marked[i] = true;
                    marked[i+1] = true;
                    marked[i+2] = true;
                    res.push_back(i+2);
                }
            }
            x = "two";
            for (int i = 0; i < s.length() - 2; i++) {
                if (!marked[i] and x.compare(s.substr(i, 3)) == 0) {
                    marked[i] = true;
                    marked[i+1] = true;
                    marked[i+2] = true;
                    res.push_back(i+2);
                }
            }
        }
        cout << res.size() << endl;
        for (auto r : res) {
            cout << r << " ";
        } cout << endl;
    }
    return 0;
}