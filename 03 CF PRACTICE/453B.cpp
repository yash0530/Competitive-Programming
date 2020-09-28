#include <bits/stdc++.h>
using namespace std;

#define INF (int) 1e9

vector<int> prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
int f(int n) {
    int res = 0;
    for (int i = 0; i < 17; i++) {
        if (n % prime[i] == 0) {
            res |= (1 << i);
        }
    }
    return res;
}

const int P = (1 << 18);
const int maxN = 101;

int dp[maxN][P];
int vals[maxN][P];

int32_t main() {

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < P; j++) {
            dp[i][j] = INF;
            vals[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (int j = 1; j <= 60; j++) {
                int F = f(j);
                if (dp[i][F] > abs(arr[i] - j)) {
                    dp[i][F] = abs(arr[i] - j);
                    vals[i][F] = j;
                }
            }
        } else {
            for (int j = 1; j <= 60; j++) {
                int F = f(j);
                for (int k = 0; k < P; k++) {
                    if ((k & F) == 0) {
                        if (dp[i][k | F] > (dp[i - 1][k] + abs(arr[i] - j))) {
                            dp[i][k | F] = dp[i - 1][k] + abs(arr[i] - j);
                            vals[i][k | F] = j;
                        }
                    }
                }
            }
        }
    }

    int res[n];
    int Final = 0, ans = INF;
    for (int i = 0; i < P; i++) {
        if (ans > dp[n - 1][i]) {
            ans = dp[n - 1][i];
            res[n - 1] = vals[n - 1][i];
            Final = i;
        }
    }
    int till_now = f(res[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        ans = INF;
        for (int j = 0; j < P; j++) {
            if ((j ^ till_now) == Final) {
                if (ans > dp[i][j]) {
                    ans = dp[i][j];
                    res[i] = vals[i][j];
                }
            }
        }
        till_now |= f(res[i]);
    }

    for (auto r : res) {
        cout << r << " ";
    } cout << endl;

    return 0;
}