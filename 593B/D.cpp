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

int32_t main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    bool possible = true;
    set<pair<int, int>> blocks;
    vector<int> rows(n + 1);
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        blocks.insert({row, col});
        if (row == 1 and col == 1) {
            possible = false;
        } else if (row == 1 and col == n) {
            possible = false;
        } else if (row == n and col == 1) {
            possible = false;
        } else if (row == n and col == n) {
            possible = false;
        } else {
            if (blocks.find({row - 1, col}) != blocks.end()) {
                possible = false;
            } else if (blocks.find({row + 1, col}) != blocks.end()) {
                possible = false;
            }
        }
        rows[row]++;
        if (rows[row] == n and row != n) {
            possible = false;
        }
        if (row == 1) {
            possible = false;
        }
    }
    if (rows[n] > 0 and rows[n] < n) {
        possible = false;
    }
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}