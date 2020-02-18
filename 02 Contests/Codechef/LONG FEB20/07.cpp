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

vector<string> pos;

void populate(int index, string s) {
    if (index == 10) {
        pos.push_back(s);
        return;
    }
    s.push_back('0');
    populate(index + 1, s);
    s.pop_back();
    s.push_back('1');
    populate(index + 1, s);
    s.pop_back();
}

// 1 -> upwards
// 0 -> downwards

int32_t main() { fastio;
    populate(0, "");
    sort(pos.begin(), pos.end());
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> joints(m);
        for (int i = 0; i < m; i++) {
            cin >> joints[i].first >> joints[i].second;
        }
        string s = "failure";
        for (int i = 0; i < (1 << m); i++) {
            set<int> vals;
            for (int x = 1; x <= n; x++) {
                int curr = x;
                for (int j = 0, k = 9; j < m and k >= 0; j++, k--) {
                    if ((joints[j].first == curr) and (pos[i][k] == '0')) {
                        curr = joints[j].second;
                    } else if ((joints[j].second == curr) and (pos[i][k] == '1')) {
                        curr = joints[j].first;
                    }
                }
                vals.insert(curr);
            }
            if (vals.size() >= ((n + 1) / 2)) {
                s = "";
                for (int k = 9, j = 0; k >= 0 and j < m; k--, j++) {
                    if (pos[i][k] == '1') {
                        s.push_back('^');
                    } else {
                        s.push_back('v');
                    }
                }
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}