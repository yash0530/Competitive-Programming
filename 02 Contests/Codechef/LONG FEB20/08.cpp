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

int rw(vector<pair<int, int>> rect) {
    return rect[1].first - rect[0].first;
}

int rh(vector<pair<int, int>> rect) {
    return rect[2].second - rect[1].second;
}

int ra(vector<pair<int, int>> rect) {
    return (rect[1].first - rect[0].first) * (rect[2].second - rect[1].second);
}

bool comp(const vector<pair<int, int>> r1, const vector<pair<int, int>> r2) {
    return ra(r1) > ra(r2);
}

vector<int> dx;
vector<int> dy;

void process(vector<pair<int, int>> &big, vector<pair<int, int>> &small, int index) {
    if (big[1].first >= small[0].first and big[1].first <= small[1].first) {
        dx[index] = big[1].first - small[1].first;
    } else if (big[0].first >= small[0].first and big[0].first <= small[1].first) {
        dx[index] = big[0].first - small[0].first;
    } else if (big[0].first >= small[1].first) {
        dx[index] = big[0].first - small[0].first;
    } else if (big[1].first <= small[0].first) {
        dx[index] = big[1].first - small[1].first;
    }
    if (big[0].second <= small[3].second and big[0].second >= small[0].second) {
        dy[index] = big[0].second - small[0].second;
    } else if (big[3].second <= small[3].second and big[3].second >= small[0].second) {
        dy[index] = big[3].second - small[3].second;
    } else if (big[0].second >= small[3].second) {
        dy[index] = big[0].second - small[0].second;
    } else if (big[3].second <= small[0].second) {
        dy[index] = big[3].second - small[3].second;
    }
    for (int i = 0; i < (int) small.size(); i++) {
        small[i].first += dx[index];
        small[i].second += dy[index];
    }
}

int32_t main() { fastio;
    int n; cin >> n;
    dx = vector<int>(n);
    dy = vector<int>(n);
    vector<vector<pair<int, int>>> rects(n);
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        vector<pair<int, int>> rect(m);
        for (int j = 0; j < m; j++) {
            cin >> rect[j].first >> rect[j].second;
        }
        rects[i] = rect;
    }
    sort(rects.begin(), rects.end(), comp);
    bool possible = true;
    for (int i = 1; i < n; i++) {
        if (rw(rects[i - 1]) >= rw(rects[i]) and rh(rects[i - 1]) >= rh(rects[i])) {
            process(rects[i - 1], rects[i], i);
        } else {
            possible = false;
            break;
        }
    }
    if (!possible) {
        cout << -1 << endl;
    } else {
        int x_trans = INT_MAX, y_trans = INT_MAX;
        for (int i = -1000; i <= 1000; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += abs(dx[j] + i);
            }
            x_trans = min(x_trans, sum);
        }
        for (int i = -1000; i <= 1000; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += abs(dy[j] + i);
            }
            y_trans = min(y_trans, sum);
        }
        cout << x_trans + y_trans << endl;
    }
    return 0;
}