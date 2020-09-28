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

struct pt {
    int x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pt> convex_hull(vector<pt> a) {
    if (a.size() == 1)
        return {};

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);

    return a;
}

double area(vector<pt> poly) {
    double res = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        res += (poly[i].x * poly[(i + 1) % n].y - poly[i].y * poly[(i + 1) % n].x);
    }
    res /= 2;
    return abs(res);
}

int32_t main() { fastio;
    int w, h, r;
    cin >> w >> h >> r;
    vector<pt> raisins(r);
    for (int i = 0; i < r; i++) {
        cin >> raisins[i].x >> raisins[i].y;
    }

    int grid = 28;

    int rows;
    for (int i = grid; i >= 1; i--) {
        if (h % i == 0) {
            rows = i; break;
        }
    }
    int cols;
    for (int i = grid; i >= 1; i--) {
        if (w % i == 0) {
            cols = i; break;
        }
    }

    vector<pt> moves;
    int _ = 2;
    vector<pt> x = raisins;
    int row_size = h / rows;
    int col_size = w / cols;
    double prev = area(convex_hull(x));
    int times = 6LL;
    for (int i = 0; i < times; i++) {
        for (int i = 1; i <= rows; i++) {
            vector<pt> temp = x;
            int high = i * row_size, low = high - row_size;
            for (int j = 0; j < r; j++) {
                if (temp[j].y >= low and temp[j].y <= high) {
                    temp[j].x = (temp[j].x + _ * col_size) % w;
                }
            }
            double curr = area(convex_hull(temp));
            if (curr < prev) {
                x = temp;
                prev = curr;
                for (int x = 0; x < _; x++) {
                    moves.push_back({ 1, i });
                }
            }
        }
        for (int i = 1; i <= cols; i++) {
            vector<pt> temp = x;
            int high = i * col_size, low = high - col_size;
            for (int j = 0; j < r; j++) {
                if (temp[j].x >= low and temp[j].x <= high) {
                    temp[j].y = (temp[j].y + _ * row_size) % h;
                }
            }
            double curr = area(convex_hull(temp));
            if (curr < prev) {
                x = temp;
                prev = curr;
                for (int x = 0; x < _; x++) {
                    moves.push_back({ 2, i });
                }
            }
        }
    }

    cout << rows << " " << cols << " " << moves.size() << endl;
    for (auto m : moves) {
        cout << m.x << " " << m.y << endl;
    }
    return 0;
}