#include <bits/stdc++.h>
using namespace std;

#define int long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int getUgly(string color, vector<vector<int>> triangles) {
    int count = 0;
    for (auto t : triangles) {
        int b = 0, r = 0, g = 0;
        for (auto x : t) {
            b += color[x - 1] == 'B';
            r += color[x - 1] == 'R';
            g += color[x - 1] == 'G';
        }
        if (b > 1 or r > 1 or g > 1) {
            count++;
        }
    }
    return count;
}

int32_t main() { fastio;
    int n, m;
    cin >> n >> m;
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    string color;
    cin >> color;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    getMat(triangles, m, 3, 0);
    for (int i = 0; i < m; i++) {
        cin >> triangles[i][0] >> triangles[i][1] >> triangles[i][2];
    }

    string color2 = color;

    int U = getUgly(color, triangles);
    int Energy = U * U;
    int color_change = 0, index = 0;

    while (index < n and color_change <= p) {
        string temp = color;
        int EB = 0;
        temp[index] = 'B';
        int Uprime = getUgly(temp, triangles);
        EB = (Uprime * Uprime) + (color[index] != 'B') * x;

        int EG = 0;
        temp[index] = 'G';
        Uprime = getUgly(temp, triangles);
        EG = (Uprime * Uprime) + (color[index] != 'G') * x;

        int ER = 0;
        temp[index] = 'R';
        Uprime = getUgly(temp, triangles);
        ER = (Uprime * Uprime) + (color[index] != 'R') * x;

        if (ER < EB and ER < EG) {
            Energy = ER;
            color_change += color[index] != 'R';
            color[index] = 'R';
        } else if (EB < EG) {
            Energy = EB;
            color_change += color[index] != 'B';
            color[index] = 'B';
        } else {
            Energy = EG;
            color_change += color[index] != 'G';
            color[index] = 'G';
        }
        index++;
    }

    int U2 = getUgly(color2, triangles);
    int Energy2 = U * U;
    int color_change2 = 0, index2 = 0;

    while (index2 >= 0 and color_change2 <= p) {
        string temp = color2;
        int EB = 0;
        temp[index2] = 'B';
        int Uprime = getUgly(temp, triangles);
        EB = (Uprime * Uprime) + (color2[index2] != 'B') * x;

        int EG = 0;
        temp[index2] = 'G';
        Uprime = getUgly(temp, triangles);
        EG = (Uprime * Uprime) + (color2[index2] != 'G') * x;

        int ER = 0;
        temp[index2] = 'R';
        Uprime = getUgly(temp, triangles);
        ER = (Uprime * Uprime) + (color2[index2] != 'R') * x;

        if (ER < EB and ER < EG) {
            Energy2 = ER;
            color_change2 += color2[index2] != 'R';
            color2[index2] = 'R';
        } else if (EB < EG) {
            Energy2 = EB;
            color_change2 += color2[index2] != 'B';
            color2[index2] = 'B';
        } else {
            Energy2 = EG;
            color_change2 += color2[index2] != 'G';
            color2[index2] = 'G';
        }
        index2--;
    }
    
    if (Energy < Energy2) {
        cout << color_change << " " << 0 << endl;
        cout << color << endl;
    } else {
        cout << color_change2 << " " << 0 << endl;
        cout << color2 << endl;
    }
    return 0;
}