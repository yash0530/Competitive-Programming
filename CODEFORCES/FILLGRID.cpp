#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

    int r, c;
    cin >> r >> c;
    int rows[r], cols[c];
    for (int i = 0; i < r; i++) {
        cin >> rows[i];
    }
    for (int i = 0; i < c; i++) {
        cin >> cols[i];
    }

    int mat[r + 1][c + 1];
    memset(mat, -1, sizeof mat);
    // 1: filled, 0: blocked, -1: can change it
    // ans is 2^(count of -1)

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < rows[i]; j++) {
            mat[i][j] = 1;
        }
        mat[i][rows[i]] = 0;
    }

    bool possible = true;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < cols[i]; j++) {
            if (mat[j][i] == 0) {
                possible = false;
                break;
            }
            mat[j][i] = 1;
        }
        if (mat[cols[i]][i] == 1) {
            possible = false;
            break;
        }
        mat[cols[i]][i] = 0;
    }

    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == -1) count++;
        }
    }

    if (possible) {
        int res = 1;
        while (count--) {
            res = (res << 1) % MOD;
        }
        cout << res << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}