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

bool comp(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) {
        if (a[2] == b[2]) {
            return a[3] < b[3];
        } return a[2] < b[2];
    }
    return a[1] < b[1];
}

int32_t main() {
    fastio;
    int n; cin >> n;
    getMat(points, n, 4, 0);
    for (int i = 0; i < n; i++) {
        points[i][0] = i + 1;
        for (int j = 1; j < 4; j++) {
            cin >> points[i][j];
        }
    }
    sort(points.begin(), points.end(), comp);

    vector<vector<int>> rem;
    for (int i = 0; i < n; i += 2) {
        if ((i == n - 1) or (points[i][2] != points[i + 1][2]) or (points[i][1] != points[i + 1][1])) {
            rem.push_back(points[i]);
            i--;
        } else {
            cout << points[i][0] << " " << points[i + 1][0] << endl;
        }
    }
    vector<vector<int>> final;
    for (int i = 0; i < rem.size(); i += 2) {
        if ((i == rem.size() - 1) or (rem[i][1] != rem[i + 1][1])) {
            final.push_back(rem[i]);
            i--;
        } else {
            cout << rem[i][0] << " " << rem[i + 1][0] << endl;
        }
    }
    for (int i = 0; i < final.size(); i += 2) {
        cout << final[i][0] << " " << final[i + 1][0] << endl;
    }
    return 0;
}