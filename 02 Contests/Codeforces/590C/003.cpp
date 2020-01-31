#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        string mat[2];

        cin >> mat[0];
        cin >> mat[1];

        queue<vector<int>> Q;
        Q.push({ 0, 0, 1 });

        int exit_possible = false;

        while (!Q.empty()) {
            auto s = Q.front(); Q.pop();
            int i = s[0], j = s[1], dir = s[2];

            if (i == 1 and j == n - 1) {
                if (dir == 1 and (mat[i][j] == '1' or mat[i][j] == '2')) {
                    exit_possible = true;
                    break;
                } else if (dir == 2 and (mat[i][j] != '1' and mat[i][j] != '2')) {
                    exit_possible = true;
                    break;
                }
            }

            if (mat[i][j] == '1' or mat[i][j] == '2') {
                if (dir == 1) {
                    if (j != n - 1) {
                        Q.push({ i, j + 1, 1 });
                    }
                } 
            } else {
                if (dir == 1) {
                    if (i == 0) {
                        Q.push({ i + 1, j, 2 });
                    } else {
                        Q.push({ i - 1, j, 3 });
                    }
                } else {
                    if (j != n - 1) {
                        Q.push({ i, j + 1, 1 });
                    }
                }
            }
        }

        if (exit_possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}